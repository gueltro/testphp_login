#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <variant>

namespace testphp_login
{
    using PageOrError = std::variant<std::string, long>;

    /// @brief Attempt login to http://testphp.vulnweb.com/login.php.
    /// @param name Username of the user attempting the login.
    /// @param password Password of the user attempting the login.
    /// @return A string containing the HTML page is succesful, else a status code.
     PageOrError Login(std::string name, std::string password);
    
    /// @brief Attempt login to http://testphp.vulnweb.com/login.php without knowing the password.
    /// @param name Username of the user attempting the login.
    /// @return A string containing the HTML page is succesful, else a status code.
     PageOrError LoginWithoutPassword(std::string name);
}

#endif /* #ifndef LOGIN_H*/
