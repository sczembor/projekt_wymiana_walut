//
//  HttpReq.cpp
//  wymiana_walut
//
//  Created by Stanislaw Czembor on 23/11/2019.
//  Copyright © 2019 Stanislaw Czembor. All rights reserved.
//

#include "HttpReq.hpp"
#include "HTTPRequest.hpp"
void httpReq::SetConfigData()
{
    std::string line, tmp1, tmp2;
    std::ifstream f("config.txt");
    if(f.is_open())
    {
        while(std::getline(f, line))
        {
            std::istringstream iss(line);
            iss >> tmp1 >> tmp2;
            if(tmp1 =="URL:")
            {
                URL = tmp2;
            }
            else if(tmp1 == "JSONfilename:")
            {
                filename = tmp2;
            }
        }
        f.close();
    }
}
void httpReq::DownloadData()
{
    http::Request request(URL);
    const http::Response getResponse = request.send("GET");
    std::ofstream f(filename);
    if(f.is_open())
    {
        f<<std::string(getResponse.body.begin(), getResponse.body.end());
    }
    
}
httpReq::httpReq()
{
    URL = filename = " ";
    SetConfigData();
    DownloadData();
}
