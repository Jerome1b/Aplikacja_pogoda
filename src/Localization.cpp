#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using namespace std;
using json = nlohmann::json;


class location {
private:
    double x;
    double y;

public:
    location(double x, double y): x(x), y(y) {}

    void mapa(){
        cout<<this->x<<" "<<this->y;
        string url = "https://www.google.com/maps/search/?api=1&query=" + to_string(this->x) + ',' + to_string(this->y);
                string command = "xdg-open \"" + url + "\"";
                int result =system(command.c_str());
    }
};


