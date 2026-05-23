#include "app.hpp"
using namespace std;

int main(){
	string miasto;
	cout << "Podaj miasto: ";
	cin >> miasto;
	CURL_Klient klient;
	Extract_data a(miasto, klient);
	a.get();
	Location p(a.x,a.y);
	Wind_inf q(a.v,a.deg);
	p.mapa();
	cout << endl << q.kat()<<endl;;
	return 0; 
}
