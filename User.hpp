//
//  User.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 30/01/2020.
//  Copyright © 2020 Stanislaw Czembor. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <string>

class user//obiekt klasy user jest przekazywany do klasy authorization i jeżeli próba logowania się powiedzie jest tworzony obiekt klasy client który dziedziczy po user
{
private:
    std::string m_username;
    std::string m_password;
public:
    //konstruktory
    user()
    :m_username(""), m_password(""){}
    user(const std::string &p_username,const std::string &p_password)
    :m_username(p_username), m_password(p_password){}
    //getery
    std::string GetUsername() const {return m_username;}
    std::string GetPassword() const {return m_password;}
};

#endif /* User_hpp */
