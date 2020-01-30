//
//  Currency.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Currency_hpp
#define Currency_hpp
#include <iostream>
class currency {
private:
    std::string name;
    long double amount;
public:
    //konstruktory
    currency()
    :name(""),amount(0){}
    currency(std::string& p_name, double p_amount = 0)
    :name(p_name),amount(p_amount){}
    //getery
    std::string GetName() const {return name;}
    double GetAmount() const {return amount;}
    //setery
    void SetAmount(double p_amount = 0){amount = p_amount;}
};

#endif /* Currency_hpp */
