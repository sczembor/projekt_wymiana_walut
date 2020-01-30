//
//  JSONParser.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//
#include <vector>
#include "JSONParser.hpp"
#include "CurrencyRates.hpp"
std::vector<currencyRates> jsonParser::parseToVector()
{
    std::vector<currencyRates> kursy;//vector przechowujący obiekty klasy currencyRates
    std::ifstream f(JSONfilename);
    if(f.is_open())
    {
        f >> file;
        f.close();
        for( const auto& currency : file[0]["rates"])
        {
            std::string code;
            code = currency["code"];
            double ask;
            ask = currency["ask"];
            double bid;
            bid = currency["bid"];
            currencyRates m(code, ask, bid);
            kursy.push_back(m);
        }
    }
    return kursy;
}
