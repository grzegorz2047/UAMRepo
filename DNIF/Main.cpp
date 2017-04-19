#include <fstream>
#include <string>
#include <iostream>
#include "stringutils.h"
#include <string>

using namespace std;



using namespace std;
int main() {

	ifstream infile("osoby.txt", ifstream::in);
	//sprawdzamy, czy plik1.txt si� otworzy�
	
	if(!infile.is_open()) {
		cerr << "Unable to open osoby.txt" << endl;
		return 1;
	}
	
	ofstream outfile("plik2.rtf", ofstream::out);
	//sprawdzamy, czy plik2.txt si� otworzy�
	
	if(!outfile.is_open()) {
		cerr << "Unable to open plik2.rft" << endl;
		return 1;
	}
	
	//w tej zmiennej b�dziemy przechowywali linie
	//odczytane z plik1.txt
	string line;
	//wczytujemy dane z plik1.txt
	int index = 1;
	while(getline(infile, line)) {
		//przerzuc linie do 2 pliku
		outfile << line << endl;
		//wypisujemy odczytan� lini� na standardowe wyj�cie
		cout << line << endl;
	    vector<string> data = split(line, ';');
	    cout << "Osoba nr. " << index << endl;
		cout << "Imi� i nazwisko: " << data[0] << endl;
		cout << "Data urodzenia: " << data[1] << endl;
		cout << "P�e�: " << data[2] << endl;
		cout << "Wzrost: " << data[3] << " m" << endl;
		cout << "Adres e-mail: " << data[4] << endl;
		cout << "Telefony: " << data[5] << endl;
		for( int i = 6; i < data.size(); i++) { 
			vector<string> phoneNumbers = split(data[i], ',');
			cout << phoneNumbers[0] << ": " << phoneNumbers[1] << endl;
		}
	    index++;

	}
	
	infile.close();
	outfile.close();
	return 0;
}
