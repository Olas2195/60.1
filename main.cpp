#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Liczby{
	ifstream plik;
	vector <int> WiekszeOd1000;
	public:
		Liczby();
		~Liczby();	
		void wczytaj();
		void wyswietl();
};

Liczby::Liczby(){
	plik.open("liczby.txt");
}
void Liczby::wczytaj(){
	int liczba;
	if(plik.good()) {
		while(!plik.eof()) {
			plik>>liczba;
			if(liczba<1000) {
				WiekszeOd1000.push_back(liczba);
			}
		}
	}
}
void Liczby::wyswietl(){
	cout<<"Ile jest liczby mniejszych od 1000? "<<WiekszeOd1000.size()<<"\n";
	cout<<"Ostatnia to: "<<WiekszeOd1000.back()<<"\n";
	WiekszeOd1000.pop_back();
	cout<<"Przedostatnia to: "<<WiekszeOd1000.back()<<"\n";
}
Liczby::~Liczby(){
	plik.close();
}

int main(int argc, char** argv) {
	Liczby l1;
	l1.wczytaj();
	l1.wyswietl();
	return 0;
}
