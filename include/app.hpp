#pragma once
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using json = nlohmann::json;
using namespace std;


extern size_t ZapisDane(void* kontent, size_t size, size_t nmemb,string* dane);

class Interface {
public:
    virtual ~Interface() {}
    virtual std::string fetch(std::string url) = 0;
};

class Extract_data{
    private:
    string city;
    Interface& client;
    string get_key();
    public:
    Extract_data(std::string city, Interface& client);
    double x;
    double y;
    double v;
    int deg;
    void get();
};

class CURL_Klient : public Interface{
    public:
    string fetch(std::string url) override; 
};

class Location{
    private:

    double x;
    double y;
    
    public:

    Location(double x, double y);
    double getX() const;
    double getY() const;
    string genUrl();
    void mapa();
};

class Wind_inf{
    private:

    const double knm = 0.6;
    const double mnk = 1.6;
    const int k =45;
    double v;
    int deg;
    bool czy_km = true;

    public:

    Wind_inf(double v, int deg);
    double conv();
    string kat();
};
