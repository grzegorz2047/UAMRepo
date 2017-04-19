#include <iostream>

using namespace std;

int main(){
	int wiersze, kolumny;
	cin >> wiersze;
	cin >> kolumny;
	int ** tab = new int*[wiersze];
    for(int i = 0; i < wiersze; i++)
	 tab[i] = new int[kolumny];

	int liczba = 1;
	for(int i = 0; i < wiersze; i++){
		for(int j = 0; j < kolumny; j++){
			tab[i][j] = liczba++;
			//cout<<tab[i][j];
			cin >> tab[i][j];
			
		}
	}
	/*cout<<endl;
	for(int i = 0; i < wiersze; i++){
		for(int j = 0; j < kolumny; j++){
			cout<< tab[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<endl;
	for(int j = 0; j < kolumny ; j++){
		for(int i = wiersze-1; i >= 0 ; i--){
			cout<< tab[i][j]<<" ";	
			//cout<<" "<<i<<" "<<j<<" ";
		}
		cout<<endl;
	}
	

}
