#include "app.hpp"


Extract_wykres::Extract_wykres(double lan, double lon, Interface& client)
    : lan(lan), lon(lon), client(client) {}


void Extract_wykres::get() {
    string link = "https://api.open-meteo.com/v1/forecast?latitude="+ to_string(lan) +"&longitude=" + to_string(lon) +"&current=temperature_2m,wind_speed_10m&hourly=temperature_2m,relative_humidity_2m,wind_speed_10m" 
;

    string resData = client.fetch(link);

    if(!resData.empty()){
        auto dane = json::parse(resData);
        for(int i=0;i<168; i+=6){
            int x = i/6;
            wind_v[x] = dane["hourly"]["wind_speed_10m"][i];
            temp[x] = dane["hourly"]["temperature_2m"][i];
            hum[x] = dane["hourly"]["relative_humidity_2m"][i];
        }
    }
}