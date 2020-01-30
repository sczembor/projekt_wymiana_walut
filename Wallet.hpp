//
//  Wallet.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Wallet_hpp
#define Wallet_hpp
#include "List.hpp"
#include <sstream>

class wallet
{
private:
    list assets;
public:
    explicit wallet(std::string buffer);
    wallet(){}
    void Display() const;
    std::string GetWalletData(){return assets.GetData();}
    double GetWalletBalance(std::string &p_currencyCode)const
    {return assets.GetValue(p_currencyCode);}
    void UpdateList(double& p_amount, std::string& p_currencyCode)
    {assets.UpdateNode(p_currencyCode, p_amount);}
    
};
#endif /* Wallet_hpp */
