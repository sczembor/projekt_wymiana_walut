//
//  List.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 24/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include "Node.hpp"

class list {
    node* pHead;
    
public:
    list()
    :pHead(nullptr){}
    list(node* p_pHead)
    :pHead(p_pHead){;}
   // list(const list & tmp) = delete;
    void AddNode(std::string p_name, double p_amount);
    //list& operator+=(
    void UpdateNode(std::string p_name, double p_amount);
    node* SearchNode(std::string p_name)const;
    double GetValue(std::string &p_name)const;
    ~list();
    void Display() const;
    list& operator=(list &&p_list);//operator przeniesienia
    std::string GetData();
};

#endif /* List_hpp */
