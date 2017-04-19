#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
	int a,b,n;
	int shot;
	int missed = 0;
	cin>>a>>b;//przedzial
	cin>>n;//liczba rzutow
	while(n > 0){
		cin>>shot;
		if(shot < a){
			missed = missed + (shot - a);
		}
		else if(shot > b){
			missed = missed + (b - shot);
		}
		else{
			missed = 0;
		}
		n--;
	}
	cout<<abs(missed)<<endl;

 return 0;
}
