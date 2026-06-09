#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <locale>
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
    int id;
    string odp;
    double tem;
    double hum;
    double x;
    double y;
    double v;
    int deg;
    void get();
};

class Extract_wykres{
	private:
	double lan;
	double lon;
    Interface& client;
	public:
	Extract_wykres(double lan, double lon, Interface& client);
    double wind_v[24];
    double temp[24];
    int hum[24];
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

    Location(float x, float y);
    float getX() const;
    float getY() const;
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

class Icon{
    private:
    int id;
    public:
    Icon(int id);
    string to_icon();
};