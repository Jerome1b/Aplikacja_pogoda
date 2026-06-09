#include "app.hpp"


Extract_wykres::Extract_wykres(double lan, double lon, Interface& client)
    : lan(lan), lon(lon), client(client) {}


void Extract_wykres::get() {
    for(int k = 0; k < 24; k++) {
        temp[k] = 0.0;
        wind_v[k] = 0.0;
        hum[k] = 0.0;
    }

    std::ostringstream urlStream;
    urlStream << "https://api.open-meteo.com/v1/forecast?latitude=" << lan
              << "&longitude=" << lon
              << "&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m";

    string link = urlStream.str();

    string resData = client.fetch(link);

    std::cout << "--- DIAGNOSTYKA CURL OPEN-METEO ---" << std::endl; //do diagnostyki
    std::cout << "Link: " << link << std::endl;
    std::cout << "Rozmiar resData: " << resData.size() << " bajtow." << std::endl;

    if(resData.empty()){
        std::cout << "[BŁĄD] CURL zwrocil PUSTY string!" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        return;
    } else {
        std::cout << "Surowy JSON (pierwsze 150 znakow): " << resData.substr(0, 150) << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    try {
        auto dane = json::parse(resData);

        if (dane.contains("hourly")) {
            auto& hourly = dane["hourly"];

            for(int i = 0; i < 24; i += 1){


                if (hourly.contains("wind_speed_10m") && !hourly["wind_speed_10m"][i].is_null()) {
                    wind_v[i] = hourly["wind_speed_10m"][i].get<double>();
                }

                if (hourly.contains("temperature_2m") && !hourly["temperature_2m"][i].is_null()) {
                    temp[i] = hourly["temperature_2m"][i].get<double>();
                }

                if (hourly.contains("relative_humidity_2m") && !hourly["relative_humidity_2m"][i].is_null()) {
                    hum[i] = hourly["relative_humidity_2m"][i].get<double>();
                }
            }
        }
    } catch (const json::exception& e) {
        std::cout << "Błąd parsowania JSON w Extract_wykres: " << e.what() << std::endl;
    }
}
