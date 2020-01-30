//
//  CurrencyRates.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef CurrencyRates_hpp
#define CurrencyRates_hpp
#include <string>
#include <iostream>

class currencyRates {
private:
    std::string name;
    double ask;
    double bid;
public:
    currencyRates();
    currencyRates(std::string &p_name, double &p_ask, double & p_bid)
    : name(p_name), ask(p_ask), bid(p_bid){;}
    //operator strumieniowy
    friend std::ostream& operator<<(std::ostream& os, const currencyRates& waluta);
    std::string getName() const {return name;}
    double getAsk() const {return ask;}
    double getBid() const {return bid;}
};

#endif /* CurrencyRates_hpp */
