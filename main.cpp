//
//  main.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "Authorization.hpp"
#include "HttpReq.hpp"
#include "JSONParser.hpp"
#include "CurrencyRates.hpp"
#include "Client.hpp"
#include "Exchange.hpp"
#include "Admin.hpp"

void DisplayCurrency();
void DisplayMenu();
void DisplayAdminMenu();
void Clear();
void DisplayLogin(std::string &login, std::string &haslo);
void WhatCurrency(int give, int get);
std::vector<currencyRates> kursy;
int main(int argc, const char * argv[])
{
    Clear();
    httpReq test;
    jsonParser m(test.getFilename());
    kursy = m.parseToVector();
    std::string login;
    std::string haslo;
    DisplayLogin(login, haslo);
    user uzytkownik(login, haslo);
    authorization proba (uzytkownik);
    if(proba.getLoginStatus())
    {
        if(proba.getUserID()==11111111)
        {
            Clear();
            std::cout<<"Udało się zalogować!\n";
            int p = 1;
            while(p)
            {
                admin admin(login, haslo);
                DisplayAdminMenu();
                int i;
                std::cin>>i;
                Clear();
                if(i==1)
                {
                    Clear();
                    admin.AddUser();
                    Clear();
                    std::cout<<"Dodano nowego użytkownika!\n";
                    
                }
                else if(i == 2)
                {
                    std::cout<<"wylogowano\n\nDo widzenia :)\n";
                    p = 0;
                }
                else
                {
                    std::cout<<"niepoprawny wybor!\n";
                }

            }
        }
        else{
        Clear();
        std::cout<<"Udało się zalogować!\n";
        int p = 1;
        client klient(login, haslo, proba.getUserID());
    while(proba.getLoginStatus()and p)
    {
        DisplayMenu();
        int i;
        std::cin>>i;
        Clear();
        if(i==1)
        {
            std::cout<<"------Aktualne kursy walut------\n";
            for(const auto& waluta : kursy)
                {
                    std::cout<<waluta.getName()<<" ask: "<<waluta.getAsk()<<" bid: "<<waluta.getBid()<<'\n';
                }
            std::cout<<"--------------------------------\n";
        }
        else if(i==2)
        {
            std::cout<<"----------Twój portfel----------\n";
            klient.Display();
            std::cout<<klient.GetAccountBallance()<<" PLN \n";
            std::cout<<"--------------------------------\n";
        }
        else if(i==3)
        {
            std::cout<<"----------Kantor----------------\n";
            DisplayCurrency();
            std::cout<<"--------------------------------\n";
            std::cout<<"wybierz kod waluty którą chcesz sprzedać:";
            std::string sell;
            std::cin>>sell;
            std::cout<<"podaj kwote do wymiany:";
            double kwota;
            std::cin>>kwota;
            std::cout<<"wybierz kod waluty którą chcesz kupić:";
            std::string buy;
            std::cin>>buy;
            std::transform(sell.begin(), sell.end(),sell.begin(), ::toupper);
            std::transform(buy.begin(), buy.end(),buy.begin(), ::toupper);
            exchange wymiana(kwota, sell, buy);
            Clear();
            std::cout<<"dostaniesz "<<wymiana.Calculate(kursy)<<" "<<buy<<'\n';
            int i =wymiana.ValidExchange(klient);
            if(i == 0)
            {
                Clear();
                std::cout<<"brak wystarczajacych srodków na koncie!\n\n";
            }
            else if (i == 1)
            {
                Clear();
                std::cout<<"proba wymiany dwoch tych samych walut!\n\n";
            }
            else if (i == 2)
            {
                wymiana.FinalizeExchange(klient);
                Clear();
                std::cout<<"wymiana powiodła się!\n\n";
            }
            klient.SaveChanges();
        }
        else if(i == 4)
        {
            std::cout<<"wylogowano\n\nDo widzenia :)\n";
            p = 0;
        }
        else
        {
            std::cout<<"niepoprawny wybor!\n";
        }
    }
    }
    }
    
    return 0;
}
void DisplayCurrency()
{
    int i = 1;
    for(const auto& waluta : kursy)
    {
        std::cout<<i<<":"<<waluta.getName()<<'\n';
        i++;
    }
}
void Clear()
{
    int i = 100;
    while(i)
    {
        std::cout<<std::endl;
        i--;
    }
}
void DisplayLogin(std::string &login, std::string &haslo)
{
    std::cout<<"Login:";
    std::cin>>login;
    std::cout<<"Hasło:";
    std::cin>>haslo;
}
void DisplayMenu()
{
    std::cout<<"--------------Menu--------------\n";
    std::cout<<"1.Wyświetl kursy\n";
    std::cout<<"2.Mój portfel\n";
    std::cout<<"3.Dokonaj wymiany\n";
    std::cout<<"4.Wyloguj\n";
    std::cout<<"--------------------------------\n";
    std::cout<<"twój wybór:";
}
void DisplayAdminMenu()
{
    std::cout<<"--------------Menu--------------\n";
    std::cout<<"1.Dodaj użytkownika\n";
    std::cout<<"2.Wyloguj\n";
    std::cout<<"--------------------------------\n";
    std::cout<<"twój wybór:";
}

