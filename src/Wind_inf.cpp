#include "app.hpp"

Wind_inf::Wind_inf(double v, int deg): v{v} deg{deg} {}

double Wind_inf::conv(){
        if(czy_km){
            czy_km = false;
            v= v*knm;
            return v;
        }
        czy_km =true;
        v = v*mnk;
        return v;
}
std::string Wind_inf::kat(){
    int s = (deg+22)/k %8;
    std::string a[] ={"N","NE","E", "SE","S","SW", "W","NW"};
    return a[s];
}