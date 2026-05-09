#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using json = nlohmann::json;
using namespace std;


extern size_t ZapisDane(void* kontent, size_t size, size_t nmemb,string* dane);


class Extarct_data{
    private:
    string city;
    bool czy_git;
    public:
    Extarct_data(std::string city);
    double x;
    double y;
    double v;
    int deg;
    string get_key();
    void get();
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
