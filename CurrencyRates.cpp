//
//  CurrencyRates.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include "CurrencyRates.hpp"
std::ostream& operator<<(std::ostream& os, const currencyRates& waluta)
{
    os<<waluta.name<<std::endl<<waluta.ask<<std::endl<<waluta.bid<<std::endl;
    return os;
}
