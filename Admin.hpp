//
//  Admin.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 30/01/2020.
//  Copyright © 2020 Stanislaw Czembor. All rights reserved.
//

#ifndef Admin_hpp
#define Admin_hpp

#include "User.hpp"

class admin: public user
{
public:
    admin() = default;
    admin(const std::string & p_username, const std::string & p_password)
    :user(p_username,p_password){}
    void AddUser();
    void SaveWallet(int p_ballance, int p_userId);
    void SaveUser(std::string & p_username, std::string & p_password, int p_userId);
};

#endif /* Admin_hpp */
