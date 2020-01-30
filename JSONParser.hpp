//
//  JSONParser.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef JSONParser_hpp
#define JSONParser_hpp
#include "json.hpp"
#include "CurrencyRates.hpp"
#include <fstream>
#include <iostream>
using json = nlohmann::json;


class  jsonParser{
    std::string JSONfilename;//nazwa pliku przechwująca plik json
    json file;//obiekt przechowujący plik json
    
public:
    explicit jsonParser(std::string p_filename)
    :JSONfilename(p_filename), file(0){;}
    jsonParser()
    :JSONfilename(" "), file(0){;}
    std::vector<currencyRates> parseToVector();//parsuje obiekt json do vectora obiektow currencyRates i zwraca go przez wartość
};
#endif /* JSONParser_hpp */
