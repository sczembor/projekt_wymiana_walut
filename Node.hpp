//
//  Node.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#include "Currency.hpp"
class node
{
private:
    node* pNext;
public:
    currency m_Currency;
    
public:
    node()
    :pNext(nullptr){}
    node(node* p_pNext, currency p_m_Currency)
    :pNext(p_pNext), m_Currency(p_m_Currency){}
    node* GetPNext() const{return pNext;}
    double GetValue() const{return m_Currency.GetAmount();}
    ~node();
};

#endif /* Node_hpp */
