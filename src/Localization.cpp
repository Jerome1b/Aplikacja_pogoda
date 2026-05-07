#include "app.hpp"
using namespace std;



Location::Location(double x, double y): x{x}, y{y} {}

double Location::getX() const {return x;}
double Location::getY() const {return y;}
std::string Location::genUrl(){
    return "https://www.google.com/maps/search/?api=1&query=" + to_string(this->x) + ',' + to_string(this->y);
}
void Location::mapa(){
    cout<<this->x<<" "<<this->y;
    string command = "xdg-open \"" + genUrl() + "\"";
    int result =system(command.c_str());
}


