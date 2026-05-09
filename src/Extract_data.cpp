#include "app.hpp"

Extarct_data::Extarct_data(string city): city{city} {}

string Extarct_data::get_key(){
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

void Extarct_data::get(){
    CURL *curl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl){
        string resData;
        string key = Extarct_data::get_key();
        string link = "https://api.openweathermap.org/data/2.5/weather?q=" + Extarct_data::city + "&appid=" + key;
        if(key == ""){
            cout <<"Nie udało się pobrać klucza" << endl;
            return;
        }

        curl_easy_setopt(curl, CURLOPT_URL, link.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ZapisDane);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA, &resData);
        
        if(curl_easy_perform(curl) == 0){
            auto dane = json::parse(resData);
            Extarct_data::x = dane["coord"]["lat"];
            Extarct_data::y = dane["coord"]["lon"];           
            Extarct_data::v = dane["wind"]["speed"];
            Extarct_data::deg = dane["wind"]["deg"];
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return;
}