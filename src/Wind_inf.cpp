#include <iostream>


class Wind_inf{
    private:
    const float knm = 0.621;
    const float mnk = 1.609;
    const int k =45;

    public:
    float v;
    int deg;
    bool czy_km = true;

    int conv(){
        if(czy_km){
            czy_km = false;
            v= v*knm;
            return v;
        }
        czy_km =true;
        v = v*mnk;
    }
    
    std::string kat(){
        int s = (deg-22)/k;
        switch(s){
            case 0:
                return "N";
            case 1:
                return "NE";
            case 2:
                return "E";
            case 3:
                return "SE";
            case 4:
                return "S";
            case 5:
                return "SW";
            case 6:
                return "W";
            case 7:
                return "NW";
        }
        return "N";
    }
};