#indef Winf_inf_H
#define Wind_inf_H
#include <bist/stdc++.h>
using namespace std;

class Wind_inf{
    private:
    const double knm;
    const double mnk;
    const int k;
    double v;
    int deg;
    bool czy_km;
    public:
    Wind_inf(double v, int deg);
    double conv();
    string kat();
};
#endif
