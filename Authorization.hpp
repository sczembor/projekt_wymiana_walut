//
//  Login.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Authorization_hpp
#define Authorization_hpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "User.hpp"

class authorization
{
protected:
    std::string usernameAttempt;
    std::string passwordAttempt;
    std::string username;
    std::string password;
    bool loginStatus;
    int userId;
public:
    authorization() = default;
    authorization(const std::string & p_username, const std::string & p_password);
    authorization(const user & p_user);
    bool VerifyLogin();
    bool getLoginStatus()const {return loginStatus;}
    int getUserID() const {return userId;}
};

#endif /* Authorization.hpp */
