#include <cstdio>
#include <iostream>
#include <vector>

int NWD(int m, int n);

	int main(){
		int sum = 0;
		std::vector <int> data;
		int entry = 0;
		do{
			std::cin>>entry;
			data.push_back(entry);
		}while(entry != 0);

		for(int i = 0; i < data.size(); i++){
			int temp = i;
			if(data[i] == 1){
				while(data[temp-1] == 1 || data[temp-2] == 1){
					temp--;				
				}	
				sum += NWD(data[temp-1], data[temp-2]);
			}
		}
		std::cout<<sum<<std::endl;
		return 0;
	}
	
	int NWD(int m, int n){
		int a = m;
		int b = n;
		while(a != b){
			if(a > b){
				a -= b;
			}else{
				b -= a;
			}
		}
		return a;
	}	
