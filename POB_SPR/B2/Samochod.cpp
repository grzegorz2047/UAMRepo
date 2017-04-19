#include <iostream>
#include <cstring>

using namespace std;


class Samochod {
	public:
		char marka[20];
		int rocznik;
		virtual void drukuj(){
			cout << marka << " " << rocznik << endl;
		}
};
class Osobowy : public Samochod {
	private:
		int liczbamiejsc;
	public:
		virtual void drukuj(){
			cout << marka << " " << rocznik << " " << liczbamiejsc << endl;
		}
};
class Ciezarowy : public Samochod {
	private: 
		int ladownosc;
	public:
		virtual void drukuj(){
			cout << marka << " " << rocznik << " " << ladownosc<< endl;
		}
};

int main(){
	Samochod s;
	strncpy(s.marka, "honda", 20);
	s.drukuj();
	Samochod *o = new Osobowy();
	strncpy(o->marka, "civic", 20);
	o->drukuj();
	Samochod *c = new Ciezarowy();
	strncpy(c->marka, "TIR", 20);
	c->drukuj();
	delete o;
	delete c;
	return 0;
}
