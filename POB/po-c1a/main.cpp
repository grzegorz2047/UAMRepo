#include <iostream>

#include "Counter.h"
#include "BadCounter.h"
#include "SuperCounter.h"

using namespace std;

int main()
{
	Counter* tab[10];
	tab[0] = new Counter();
	tab[1] = new SuperCounter();
	tab[2] = new BadCounter();
	tab[3] = new Counter();
	tab[4] = new SuperCounter();
	tab[5] = new BadCounter();
	tab[6] = new Counter();
	tab[7] = new SuperCounter();
	tab[8] = new BadCounter();
	tab[9] = new Counter();
	for(int i = 0; i < 10; i++) {
		tab[i]->set(i+4);
		tab[i]->incr();
		cout << "Licznik nr. " << i << " Wartosc to " << tab[i]->get() << endl;
		tab[i]->incr();
		cout << "Licznik nr. " << i << " Wartosc to " << tab[i]->get() << endl;
		tab[i]->incr();
		cout << "Licznik nr. " << i << " Wartosc to " << tab[i]->get() << endl;
		cout << endl;
	}
	delete [] tab;
}
