#include <cstdio>
#include <iostream>
#include <vector>

	void addNotes(std::vector <int> &data);
	void printNotes(std::vector <int> &data);
	void avgNotes();
	int interpretData(std::vector <int> &data);

	int main(){
		std::vector < int > data;
		addNotes(data);
		return interpretData(data);
	}
	void addNotes(std::vector <int> &data){
		int i=0;
		while(i != -1){
			std::cin>>i;
			data.push_back(i);
		}
	}
	void printNotes(std::vector <int> &data, int cursor){
		for(int i=0; i < cursor;i++){
			if(data[i] != 1 && data[i] != 0 && data[i] != -1){
				std::cout<<data[i]<<" ";
			}
		}
	}
	void avgNotes(std::vector <int> &data, int cursor){
		double sum = 0;
		double count = 0;
		for(int i = 0; i < cursor;i++){
			if(data[i] != 1 && data[i] != 0 && data[i] != -1){
				//std::cout<<data[i]<<" ";
				sum+=data[i];
				count++;
			}
		}
		double avg = sum/count;
		printf("%.2f", avg);
	}
	int interpretData(std::vector <int> &data){
		int cursor = 0;
		for(int i=0; i < data.size();i++){
			cursor++;
			if(data[i] == 1){
				avgNotes(data, cursor);
				std::cout<<std::endl;
			}else if(data[i] == 0){
				printNotes(data, cursor);
				std::cout<<std::endl;
			}else if(data[i] == -1){
				return 0;
			}
		}
		return 0;
	
	}
	
