#include <iostream>

using namespace std;

int main(){
	int * tab;
	int entry = 0;
	int liczba = 0;
	cin >> entry;
	tab = new int[entry];
	int i = 0;//liczba dodanych liczb
	while(i < entry){
		cin >> liczba;
		tab[i] = liczba;
		i++;
	}
	
	for(i = i-1; i > 0;i--){
		int from1 = i+1;
		if(from1 % 2 == 0){
			cout<<tab[i];
		}
	}

	

	delete [] tab;
}
