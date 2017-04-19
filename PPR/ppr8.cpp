#include <iostream>

using namespace std;

int main(){
	int candNr = 0;
	int voteNr = 0;
	cin >> candNr;
	cin >> voteNr;
	int * tab = new int[candNr];
	int candId = 0;
	while(voteNr > 0){
		cin >> candId;
		tab[candId-1] = tab[candId-1] +1;
		voteNr--;
	}

	for(int i = 0; i < candNr; i++){
		cout<<(i+1)<<": "<<tab[i]<<endl;
	}

	int maxVotes = 1;
	int highestNumVotes = tab[0];
	for(int i = 0; i < candNr; i++){
		if(highestNumVotes < tab[i]){
			highestNumVotes = tab[i];
			maxVotes= 1;
			candId = i+1;
		}
		else if(highestNumVotes == tab[i]){
			maxVotes++;
		}
	}
	cout<<candId;



}
