#include <bits/stdc++.h>

class Location{
    private:

    double x;
    double y;
    
    public:

    Location(double x, double y);
    double getX() const;
    double getY() const;
    std::string genUrl();
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
    std::string kat();
};
