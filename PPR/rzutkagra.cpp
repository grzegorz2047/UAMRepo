#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
	int a,b,n;
	int shot;
	int missed = 0;
	cin>>a>>b;//przedzial
	cin>>shot;//miejsce rzutu
	if(shot < a){
		missed = missed + (shot - a);
	}
	else if(shot > b){
		missed = missed + (b - shot);
	}
	else{
		cout<<"BINGO"<<endl;
	}
	if(missed != 0){
		cout<<abs(missed)<<endl;
	}
	

 return 0;
}
