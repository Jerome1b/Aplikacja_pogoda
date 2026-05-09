#include "app.hpp"

size_t ZapisDane(void* kontent, size_t size, size_t nmemb, string* dane){
    dane->append((char*)kontent, size * nmemb);
    return size * nmemb;
}
