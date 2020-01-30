//
//  Login.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//
#include "Authorization.hpp"
authorization::authorization(const std::string & p_username, const std::string & p_password)
{
    username = p_username;
    password = p_password;
    userId = 0;//wartosc 0 jest niepoprawna wartością i nie odpowiada zadnemu uzytkownikowi
    loginStatus = VerifyLogin();
    if(loginStatus)
    {
        std::cout<<"znaleziono klienta o numerze identyfikacyjnym :"<< userId<<"\n";
    }
}
authorization::authorization(const user & p_user)
{
    username = p_user.GetUsername();
    password = p_user.GetPassword();
    userId = 0;//wartosc 0 jest niepoprawna wartością i nie odpowiada zadnemu uzytkownikowi
    loginStatus = VerifyLogin();
    if(loginStatus)
    {
        std::cout<<"znaleziono klienta o numerze identyfikacyjnym :"<< userId<<"\n";
    }
}


bool authorization::VerifyLogin()
{
    bool accessGranted = false;
    std::string line;
    std::string f_username, f_password;//zmienne do przetrzymywania
    int f_userId;                      //wczytanych informacji z pliku
    std::ifstream f("log_info.txt");
    if(f.is_open())
    {
        while(!accessGranted && std::getline(f, line))
        {
            std::istringstream iss(line);
            if(!(iss >> f_username >> f_password >> f_userId))
            {
                //pusty wiersz
            }
            else if(username == f_username && password == f_password)
            {
                accessGranted = true;
                userId = f_userId;
                f.close();
                return accessGranted;
            }
        }
        f.close();//zamknięcie pliku
        return accessGranted;
    }
    else
    {
        std::cout<<"file error :(\n ";
    }
    return accessGranted;
}
