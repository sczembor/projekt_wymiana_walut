//
//  List.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include "List.hpp"

void list::AddNode(std::string p_name,double p_amount)//metoda dodająca węzeł na poczatek listy jednokierunkowej
{
    currency m(p_name,p_amount);
    node* tmp = pHead;
    pHead = new node(tmp,m);
}
node* list::SearchNode(std::string p_name)const
{
    node* tmp = pHead;
    while(tmp)
    {
        if(tmp->m_Currency.GetName() == p_name)
        {
            return tmp;
        }
        else
        {
            tmp = tmp->GetPNext();
        }
    }
    return nullptr;
}
double list::GetValue(std::string &p_name)const
{
    node* tmp = this->SearchNode(p_name);
    if(tmp)
    {
        return tmp->GetValue();
    }
    else
        return -1;
}
void list::UpdateNode(std::string p_name, double p_amount)
{
    node* tmp = SearchNode(p_name);
    if(tmp)
    {
        tmp->m_Currency.SetAmount(tmp->m_Currency.GetAmount()+p_amount);
    }
    else
    {
        AddNode(p_name, p_amount);
    }
}
//destruktor
list::~list()
{
    if(pHead!= nullptr)
    {
        node* tmp;
        while(pHead)
        {
            tmp = pHead;
            pHead = pHead->GetPNext();
            delete tmp;
        }
      //  delete pHead;
        pHead = nullptr;
    }
    //std::cout<<"destruktor list\n";
}
void list::Display() const
{
    node* tmp = pHead;
    while(tmp)
    {
        std::cout<<tmp->m_Currency.GetAmount()<<" "<<tmp->m_Currency.GetName()<<"\n";
        tmp = tmp->GetPNext();
    }
    tmp = nullptr;
}
list& list::operator=(list &&p_list)//operator przeniesienia
{
    pHead = p_list.pHead;
    p_list.pHead = nullptr;
    return *this;
}

std::string list::GetData()
{
    node* tmp = pHead;
    std::string s_tmp{};
    while(tmp)
    {
        s_tmp+=" ";
        s_tmp+=tmp->m_Currency.GetName();
        s_tmp+=" ";
        s_tmp+=std::to_string(tmp->m_Currency.GetAmount());
        tmp = tmp->GetPNext();
    }
    tmp = nullptr;
    return s_tmp;
}
