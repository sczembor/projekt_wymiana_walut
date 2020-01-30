//
//  HttpReq.hpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#ifndef HttpReq_hpp
#define HttpReq_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
class httpReq//klasa która pobiera dane z internetu i tworzy plik w formacie JSON
{
private://skladowe prywatne
    std::string URL;//adres strony do pobierania kursów walut w foramcie JSON
    std::string filename;//nazwa pliku w ktorym znajdują się kursy
private://metody prywatne
    void SetConfigData();
    void DownloadData();
public://metody publiczne
    httpReq();
    std::string getFilename() const{return filename;}
    
};

#endif /* HttpReq_hpp */
