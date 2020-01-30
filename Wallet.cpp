//
//  Wallet.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include "Wallet.hpp"
wallet::wallet(std::string buffer)
{
   // std::cout<<"konstruktor argumentowy wallet\n";
    std::istringstream iss(buffer);
    std::string nameTmp;
    double amountTmp;
    iss>>amountTmp>>nameTmp>>amountTmp;
    while (iss>>nameTmp && iss>> amountTmp)
    {
        assets.AddNode(nameTmp,amountTmp);
    }
}
void wallet::Display() const
{
    assets.Display();
}

