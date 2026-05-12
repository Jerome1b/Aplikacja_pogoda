#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include "app.hpp"
using namespace std;
using json = nlohmann::json;


class Interface {
public:
    virtual ~Interface() {};
    virtual string fetch(string url) = 0;
};

class CURL_Klient : public Interface {
    string fetch(string url) override {
        CURL *curl;
        string resData;
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ZapisDane);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &resData);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        }
        return resData;
    }
};

class Extarct_data {
private:
    string city;
    Interface& client;

    string get_key() {
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

public:
    double x, y, v, deg;
    
    Extarct_data(string city, Interface& client) : city(city), client(client) {}

    void get() {
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
};

class MockWeather : public Interface {
public:
    string fetch(string url) override {
        return R"({
            "coord": {"lat": 50.06, "lon": 19.94},
            "wind": {"speed": 5.5, "deg": 180},
            "name": "Krakow"
        })";
    }
};

void test_get_data() {
    MockWeather mock; 
    Extarct_data testObj("Krakow", mock);

    testObj.get();

    if(testObj.x == 50.06 && testObj.v == 5.5) {
        cout << "TEST ZALICZONY!" << endl;
    } else {
        cout << "TEST OBLANY!" << endl;
    }
}

int main() {
    test_get_data();
}
