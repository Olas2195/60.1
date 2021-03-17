#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int nwd(int x, int y)
{
    if (x < y)
        return nwd(y, x);
    if (y == 0)
        return x;
    return nwd(y, x%y);
}

class Collection {
    vector <int> liczby;
    vector <int> wzglednie_pierwsze;
    
  	public:
      	bool file_read();
      	void porownania();
     	int max();
};

bool Collection::file_read() {
    ifstream file;
    file.open("liczby.txt");
    int number;
    
	if (!file.good()){ 
       cout << "Pliku nie mo¿na otworzyæ!!";
       return false;
    }

    int counter_readed = 0;    
    while (!file.eof()) {
       file>>number;
       liczby.push_back(number);
    }
    file.close();
    return true;
}

void Collection::porownania(){
	int pierwsza;
	for (int i = 0; i < liczby.size(); i++) {
		pierwsza = 0;
		for (int j=0; j < liczby.size(); j++) {
			if(j!=i) {
				if(nwd(liczby[i],liczby[j])==1) {
					pierwsza++;
				}
			}
		}
		if(pierwsza==liczby.size()-1) {
			wzglednie_pierwsze.push_back(liczby[i]);
		}
	}
}
int Collection::max() {
	int najwieksza = 0;
	for(int i =0;i<wzglednie_pierwsze.size(); i++) {
		if(wzglednie_pierwsze[i]>najwieksza) {
			najwieksza = wzglednie_pierwsze[i];
		}
	}
	return najwieksza;
}


int main(int argc, char** argv) {
    Collection numbers;
	if (numbers.file_read()) {
		numbers.porownania();
		cout<<numbers.max();
	}
    return 0;
}
