#include <iostream>


class Wind_inf{
    private:
    const double knm = 0.6;
    const double mnk = 1.6;
    const int k =45;
    double v;
    int deg;
    bool czy_km = true;
    public:


    Wind_inf(double v, int deg): v{v}, deg{deg} {}

    double conv(){
        if(czy_km){
            czy_km = false;
            v= v*knm;
            return v;
        }
        czy_km =true;
        v = v*mnk;
        return v;
    }
    
    std::string kat(){
        int s = (deg+22)/k %8;
        std::string a[] ={"N","NE","E", "SE","S","SW", "W","NW"};
        return a[s];
    }
};
