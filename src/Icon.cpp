#include "app.hpp"

Icon::Icon(int id): id{id} {}

string Icon::to_icon(){
    switch(id){
        case 200 ... 231:
            return "\u26C8\uFE0F";
        case 300 ... 321:
            return "\U0001F326\uFE0F";
        case 500 ... 531:
            return "\U0001F327\uFE0F";
        case 600 ... 622:
            return "\u2744\uFE0F";
        case 700 ... 781:
            return "\U0001F32B\uFE0F";
        case 800:
            return "\u2600\uFE0F";
        case 801:
            return "\u26C5\uFE0F";
        case 802:
        case 803:
        case 804:
            return "\u2601\uFE0F";
        default:
            return "";
    }
}