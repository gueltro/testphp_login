#include <iostream>
#include <string>

#include "login.h"

struct ResponseVisitor {
    void operator() (std::string& page) {
        std::cout << page;
    }

    void operator() (long error) {
        std::cout << "Something went wrong! Received status " << error << std::endl;
    }
};

/// @brief Prints the page or the error.
/// @param page_or_error The page or error to be printed.
void PrintPageOrError(testphp_login::PageOrError page_or_error) {
    std::visit(ResponseVisitor{}, page_or_error);
}

/// @brief Print the instructions in case the arguments provided were invalid.
void PrintInstruction() {
    std::cout << "testphp_login only accepts one or two arguments." << std::endl;
    std::cout << "You must specify a USERNAME and optionally a PASSWORD with the following syntax:" << std::endl;
    std::cout <<  "testphp_login USERNAME PASSWORD" << std::endl;
    std::cout <<  "testphp_login USERNAME" << std::endl;
}

// main only deals with processing user input and printing output.
// All of the logic for logging in is hidden in testphp_login_lib and exposed through login.h.
int main(int argc, char** argv) {
    // Username and password were provided.
    if (argc == 3) {
	PrintPageOrError(testphp_login::Login(argv[1], argv[2]));
    }
    // Only username was provided.
    else if (argc == 2) {
	PrintPageOrError(testphp_login::LoginWithoutPassword(argv[1]));
    }
    // Invalid input, teach the user how to use this app.
    else {
	PrintInstruction();
    }

    return 0;
}
