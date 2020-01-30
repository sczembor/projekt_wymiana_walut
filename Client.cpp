//
//  Client.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.

#include "Client.hpp"
std::string client::GetFileData()
{
    std::string line = "";
    int m_userID;
    std::ifstream f(filename);
    if(f.is_open())
    {
        while(std::getline(f, line))
        {
            std::istringstream iss(line);
            iss >> m_userID;
            if(m_userID == userId)
            {
                //wczytywanie znaków i tworzenie walleta
                std::string codeTmp;
                double amountTmp;
                iss>>codeTmp;//wczytanie PLN
                if(codeTmp == "PLN")
                {
                    iss>>amountTmp;
                    accountBallance = amountTmp;
                }
                return line;
            }
        }
        f.close();
    }
    return line;
}
void client::SetFilename()
{
    std::string line, tmp1, tmp2;
    std::ifstream f("config.txt");
    if(f.is_open())
    {
        while(std::getline(f, line))
        {
            std::istringstream iss(line);
            iss >> tmp1 >> tmp2;
            if(tmp1 =="Walletfilename:")
            {
                filename = tmp2;
            }
        }
        f.close();
    }
}
client::client(const std::string & p_username, const std::string & p_password, int p_userID)
:user(p_username,p_password)
{
    userId = p_userID;
   // std::cout<<"konstruktor argumentowy client\n";
    SetFilename();
    m_wallet = wallet(GetFileData());
}
client::client()
{
    //std::cout<<"konstruktor bezargumentowy client\n";
    accountBallance = 0;
    userId = 0;
    filename = "";
}
void client::SaveChanges()
{
    std::ifstream fin(filename);
    std::vector<std::string>lines;
    std::string input;
    while (std::getline(fin, input))
        lines.push_back(input);

    for (auto& line : lines)
    {
//        if (compare(line))
//            modify(line);
        if(*this==line)
        {
            modify(line);
        }
    }

    fin.close();

    std::ofstream fout(filename);
    for (auto const &line :lines)
        fout<<line<<'\n';
    
}
void client::modify(std::string &line)
{
    std::string tmp{};
    tmp += std::to_string(userId);
    tmp += " PLN ";
    tmp += std::to_string(accountBallance);
    tmp += GetWalletData();
    line = tmp;
}
bool client::compare(std::string &line)
{
    int m_userID = 0;
    std::istringstream iss(line);
    iss >> m_userID;
    if(m_userID ==userId)
    {
        return true;
    }
    return false;
}
bool client::operator==(std::string &line)
{
    int m_userID = 0;
       std::istringstream iss(line);
       iss >> m_userID;
       if(m_userID ==userId)
       {
           return true;
       }
       return false;
}
std::ostream& operator<<(std::ostream & os, const client & p_client)
{
    p_client.m_wallet.Display();
    std::cout<<p_client.GetAccountBallance()<<" PLN\n";
    return os;
}
