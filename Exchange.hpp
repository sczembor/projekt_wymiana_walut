//
//  Exchange.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 27/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Exchange_hpp
#define Exchange_hpp

#include <string>
#include <vector>
#include "Client.hpp"
#include "CurrencyRates.hpp"

class exchange
{
    double m_amount;//kwota do wymiany
    std::string m_bidCurrencyCode;//kod waluty do sprzedazy
    std::string m_askCurrencyCode;//kod waluty do kupna
    static int m_caseNum;//numer wyjatku
    double m_askAmount;//kwota ktora chce uzyskac
    //1 oznacza ze wymiana tej samej waluty na tą samą walute nie ma sensu odpalac calej logiki wymiany
    //2 mbid = PLN
    //3 wymiana dwoch walut obcych
public:
    //konstruktory
    exchange()
    :m_amount(0), m_bidCurrencyCode(""), m_askCurrencyCode(""){m_askAmount = 0;}
    exchange(double p_amount, std::string p_bidCurrencyCode, std::string p_askCurrencyCode)
    :m_amount(p_amount), m_bidCurrencyCode(p_bidCurrencyCode), m_askCurrencyCode(p_askCurrencyCode){m_askAmount = 0;}
    //metody publiczne
    double Calculate(const std::vector<currencyRates> & p_rates);
    int ValidExchange(const client &p_client)const;//funckja sprawdzająca czy klient posiada wystarczające środki na koncie
    void FinalizeExchange(client &p_client);
};
#endif /* Exchange_hpp */
