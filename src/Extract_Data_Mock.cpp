#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include "app.hpp"

using namespace std;
using json = nlohmann::json;

// Tylko implementacja metody fetch
string CURL_Klient::fetch(string url) {
    CURL *curl;
    string resData;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ZapisDane);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return resData;
}

// Tylko implementacje metod Extract_data
string Extract_data::get_key() {
    ifstream file(".env");
    string line;
    if(file.is_open()){
        while(getline(file,line)){
            if(!line.find("KEY=")){
                return line.substr(4);
            }
        }
        file.close();
    }
    return "";
}

Extract_data::Extract_data(std::string city, Interface& client) 
    : city(city), client(client) {}

void Extract_data::get() {
    string key = get_key();
    string link = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + key;

    string resData = client.fetch(link);

    if(!resData.empty()){
        auto dane = json::parse(resData);
        x = dane["coord"]["lat"];
        y = dane["coord"]["lon"];           
        v = dane["wind"]["speed"];
        deg = dane["wind"]["deg"];
    }
}
