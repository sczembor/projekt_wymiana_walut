//
//  Client.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp
#include "Wallet.hpp"
#include "Authorization.hpp"
#include "User.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
class client: public user
{
private:
    double accountBallance;//ile zlotówek ma na kocnie PLN
    int userId;//wedug tego bedzie szukal infro o portfelu w osobnym pliku
    wallet m_wallet;
    std::string filename;
    
private://metody prywante
    std::string GetFileData();
    void SetFilename();
public:
    //konstruktory
    explicit client(const int);
    client(const std::string & p_username, const std::string & p_password, int p_userID);
    client();//blokuje automatyke konwersji, dany konstruktor nie moze być wywołany niejawnie
    //getery
    double GetAccountBallance() const {return accountBallance;}
    std::string GetWalletData(){return m_wallet.GetWalletData();}
    void UpdateAccountBallance(double& p_amount){accountBallance -= p_amount;}
    void Display() const{m_wallet.Display();}
    double GetWalletBallance(std::string &p_currencyCode) const
    {return m_wallet.GetWalletBalance(p_currencyCode);}
    void UpdateWallet(double& p_amount, std::string& p_currencyCode)
    {m_wallet.UpdateList(p_amount, p_currencyCode);}
    virtual void SaveChanges();
    void modify(std::string &line);
    bool compare(std::string &line);
    //operatory
    void UpdateLoginStatus(std::string p_login, std::string p_password);
    bool operator==(std::string &line);//przeciążony operator porównania
    friend std::ostream& operator<<(std::ostream &, const client &);//operator strumienowy
};

#endif /* Client_hpp */
