#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>

std::string printTextBoom(int letterCount);

	int main(){
		int count = 0;
		int letterCount = 0;
		std::cin>>count;
		std::string allwords;
		std::string * tab = new std::string[count];
		int tabIndex = 0;
		while(count != 0){
			count--;
			std::cin>>letterCount;
			tab[tabIndex] = printTextBoom(letterCount);
			tabIndex++;
		}
		for(int i=0; i< tabIndex;i++){
			std::cout<<tab[i]<<std::endl;
		}
		return 0;
	}

	std::string printTextBoom(int letterCount){
		std::string wordpart1 = "B";
		std::string wordpart2 = "B";
		std::string wordpart3 = "";
		for(int i=0; i<letterCount; i++){
			wordpart1.append("I");
		}
		wordpart1.append("G");
		wordpart1.append(" ");
		for(int i=0; i<letterCount; i++){
			wordpart2.append("O");
		}
		wordpart2.append("M");
		for(int i=0; i<letterCount; i++){
			wordpart3.append("!");
		}
		wordpart1.append(wordpart2);
		wordpart1.append(wordpart3);
		return wordpart1;
	}
	
	
