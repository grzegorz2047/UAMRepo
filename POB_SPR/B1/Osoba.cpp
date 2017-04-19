#include <cstring>
#include <iostream>

using namespace std;

class Osoba {
	private:
		char* nazwisko;
		int wiek;
	public:
		Osoba(char* nazwisko, int wiek){
			this->nazwisko = nazwisko;
			this->wiek = wiek;
		}
		Osoba(const Osoba& osoba){
			nazwisko = new char[strlen(osoba.nazwisko)+1];
			strcpy(nazwisko, osoba.nazwisko);
			wiek = osoba.wiek;
		}
		~Osoba(){
			//delete [] nazwisko; nie
		}
		void ustawNazwisko(char* nazwisko){
			this->nazwisko = nazwisko;
		}
		void ustawWiek(int wiek){
			this->wiek = wiek;
		}
		bool operator ==(Osoba& o){
			//cout << this->nazwisko << " " << o.nazwisko << " " << this->wiek << " " << o.wiek << endl; 
			if(strncmp(this->nazwisko, o.nazwisko, strlen(o.nazwisko)) == 0){
				if(this->wiek == o.wiek){
					return true;
				}
			}else{
				return false;
			}
		}
		
};

int main(){
	Osoba o("test", 18);
	Osoba os(o);
	if(o == os){
		cout << "tak" << endl;
	}else{
		cout << "nie" << endl;
	}
	return 0;
}
