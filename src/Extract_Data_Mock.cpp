#include "app.hpp"

using namespace std;
using json = nlohmann::json;

//fetch
string CURL_Klient::fetch(string url) {
    CURL *curl;
    string resData;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        size_t qPos = url.find("q=");
        if (qPos != string::npos) {
            size_t appidPos = url.find("&appid=", qPos);
            string prefix = url.substr(0, qPos + 2);
            string cityPart = (appidPos != string::npos)
                                  ? url.substr(qPos + 2, appidPos - (qPos + 2))
                                  : url.substr(qPos + 2);
            string suffix = (appidPos != string::npos) ? url.substr(appidPos) : "";

            char* escapedCity = curl_easy_escape(curl, cityPart.c_str(), cityPart.length());
            if (escapedCity) {
                url = prefix + escapedCity + suffix;
                curl_free(escapedCity);
            }
        }


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ZapisDane);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resData);

        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cout << "[CURL ERROR] Blad sieci: " << curl_easy_strerror(res) << std::endl; //do diagnostyki
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return resData;
}


string Extract_data::get_key() {
    ifstream file(".env");


    if (!file.is_open()) {
        return "";
    }

    string line;
    if(file.is_open()){
        while(getline(file,line)){
            if(!line.find("KEY=")){
                file.close();
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


    if(key.empty()) {
        std::cout << "[BŁĄD] Nie udało się wczytać klucza API z pliku .env!" << std::endl; //do diagnostyki
        x = 50.06;
        y = 19.94;
        v = 0.0;
        deg = 0;
        return;
    }

    string link = "https://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + key;
    string resData = client.fetch(link);
    std::cout << "--- CO DOKŁADNIE ZWRÓCIŁ SERWER ---" << std::endl; //do diagnostyki
    std::cout << resData << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    if(!resData.empty()){
        try {
            auto dane = json::parse(resData);


            if (dane.contains("coord") && !dane["coord"].is_null()) {
                x = dane["coord"].value("lat", 0.0);
                y = dane["coord"].value("lon", 0.0);
            } else {
                std::cout << "[Ostrzeżenie] JSON nie zawiera sekcji 'coord'. Prawdopodobnie błędny klucz API!" << std::endl;
                x = 50.06;
                y = 19.94;
            }

            if (dane.contains("wind") && !dane["wind"].is_null()) {
                v = dane["wind"].value("speed", 0.0);
                deg = dane["wind"].value("deg", 0);
            } else {
                v = 0.0;
                deg = 0;
            }

            if (dane.contains("weather") && !dane["weather"].is_null()) {
                id = dane["weather"][0].value("id", 0);
            } else {
                id = 0;
            }

            if (dane.contains("cod")) {
                if (dane["cod"].is_string()) {
                    odp = dane["cod"];
                } else if (dane["cod"].is_number()) {
                    string c = to_string(dane["cod"]);
                    odp = c;
                }
            } else {
                odp = "0";
            }

        } catch (const json::exception& e) {
            std::cout << "Błąd parsowania JSON w Extract_data: " << e.what() << std::endl;
            x = 50.06;
            y = 19.94;
        }
    }
}
