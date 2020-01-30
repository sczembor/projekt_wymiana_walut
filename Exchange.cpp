//
//  Exchange.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 27/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include "Exchange.hpp"

//inicjalizacja statycznej składowej klasy exchange
int exchange::m_caseNum = 0;


//definicje metod klasy
double exchange::Calculate(const std::vector<currencyRates> & p_rates)
{
    if(m_askCurrencyCode == m_bidCurrencyCode)
    {
        m_caseNum = 1;
        return m_amount;
    }
    double ask{}, bid{}, returnVal{};
    for(const auto& waluta : p_rates)
    {
        if(waluta.getName() == m_bidCurrencyCode)
        {
            bid = waluta.getBid();
        }
        if(waluta.getName() == m_askCurrencyCode)
        {
            ask = waluta.getAsk();
            
        }
    }
    if(m_bidCurrencyCode == "PLN")
    {
        m_askAmount = m_amount/ask;
        m_caseNum = 2;
        return m_amount/ask;
    }
    else if(m_askCurrencyCode  == "PLN")
    {
        m_askAmount = m_amount*bid;
        m_caseNum = 4;
        return m_amount*bid;
    }
    else
    {
        m_askAmount = (m_amount*bid)/ask;
        m_caseNum = 3;
        returnVal = m_amount*bid;
        return returnVal/ask;
    }
}
 int exchange::ValidExchange(const client &p_client) const
{
    std::string tmp  =m_bidCurrencyCode;
    switch (m_caseNum)
    {
        case 1:
            return 1;//liczba 1 ozacza koniecznosc wyswietlenia komunikatu o proby wymiany dwoch tych samych walut
            break;
        case 2:// wymiana pln na inna walute
            return (p_client.GetAccountBallance()>=m_amount)?2:0;//liczba 2 oznacza wystarczające srodki na koncie i koniecznoac przeprowadzenia tranzakcji , liczba 0 oznacza koniecznosc wyswietlenia komunikatu o braku wystarczajacych srodkow na koncie
            break;
        case 3:
            return (p_client.GetWalletBallance(tmp)>=m_amount)?2:0;
            break;
        case 4:
            return (p_client.GetWalletBallance(tmp)>=m_amount)?2:0;
            break;
        default:
            return 0;
            break;
    }
}
void exchange::FinalizeExchange(client &p_client)
{
    if(m_caseNum == 2)
    {
        p_client.UpdateAccountBallance(m_amount);
        p_client.UpdateWallet(m_askAmount, m_askCurrencyCode);
    }
    else if (m_caseNum == 3)
    {
        m_amount *=(-1);
        p_client.UpdateWallet(m_amount, m_bidCurrencyCode);
        p_client.UpdateWallet(m_askAmount, m_askCurrencyCode);
    }
    else if (m_caseNum == 4)
    {
        m_amount *=(-1);
        p_client.UpdateWallet(m_amount, m_bidCurrencyCode);
        m_askAmount *=(-1);
        p_client.UpdateAccountBallance(m_askAmount);
    }
}
