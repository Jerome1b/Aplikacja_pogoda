#include "app.hpp"

int main(){
	string city;
	cout << "Podaj miasto: ";
	cin >> city;
	Extarct_data a(city);
	a.get();
	Location p(a.x,a.y);
	Wind_inf q(a.v,a.deg);
	p.mapa();
	cout << endl << q.kat()<<endl;;
	return 0; 
}
