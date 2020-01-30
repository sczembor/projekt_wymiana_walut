//
//  Admin.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 30/01/2020.
//  Copyright © 2020 Stanislaw Czembor. All rights reserved.
//

#include "Admin.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

void admin::AddUser()
{
    //zbieranie informacji od admina
    std::cout<<"Podaj Login:";
    std::string login;
    std::cin>>login;
    std::cout<<"Podaj Hasło:";
    std::string haslo;
    std::cin>>haslo;
    std::cout<<"Podaj stan konta w zlotówkach np.(8450.42):";
    double stan_konta;
    std::cin>>stan_konta;
    srand((unsigned int)(time(NULL)));
    int userID = rand();//wygenerowanie numeru ID
    //zapisanie zmian do pliku
    SaveUser(login, haslo, userID);
    SaveWallet(stan_konta, userID);
    std::cout<<"\nDodano nowego użytkownika!\n";
}
void admin::SaveWallet(int p_ballance, int p_userId)
{
    std::ifstream fin("walletINFO.txt");
    std::vector<std::string>lines;
    std::string input;
    while (std::getline(fin, input))
    {
        lines.push_back(input);
    }
    fin.close();
    std::ofstream fout("walletINFO.txt");
    for (auto const &line :lines)
    {
        fout<<line<<'\n';
    }
    fout<<p_userId<<" PLN "<<p_ballance<<"\n";
    fout.close();
}
void admin::SaveUser(std::string & p_username, std::string & p_password, int p_userId)
{
    std::ifstream fin("log_info.txt");
    std::vector<std::string>lines;
    std::string input;
    while (std::getline(fin, input))
    {
        lines.push_back(input);
    }
    fin.close();
    std::ofstream fout("log_info.txt");
    for (auto const &line :lines)
    {
        fout<<line<<'\n';
    }
    fout<<p_username<<" "<<p_password<<" "<<p_userId<<"\n";
    fout.close();
}
    

