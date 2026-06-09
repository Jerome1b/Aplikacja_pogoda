#include "app.hpp"
using namespace std;



Location::Location(float x, float y): x{x}, y{y} {}

float Location::getX() const {return x;}
float Location::getY() const {return y;}
std::string Location::genUrl(){
    std::ostringstream ss;
    ss.imbue(std::locale::classic());
    //musielismy zrobic to w ten sposob, bo zamiast kropek, to_string() dodaje do double ',' zamiast '.', co sprawia, ze mapa sie zle odpala
    ss << "https://www.openstreetmap.org/?mlat=" << this->x
       << "&mlon=" << this->y
       << "#map=13/" << this->x << "/" << this->y;

    return ss.str();
}
void Location::mapa(){
    cout<<this->x<<" "<<this->y;
    string command = "xdg-open \"" + genUrl() + "\"";
    int result =system(command.c_str());
}


