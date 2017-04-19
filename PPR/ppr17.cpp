#include <iostream>
#include <string>
 int sum = 0;

  int checkCandidate(int * tab, int numOfdzielniki, int KandydatNumber){
    int passedDzielniki = 0;
    for(int i = 0; i < numOfdzielniki; i++){
      if (KandydatNumber % tab[i] == 0){
        //std::cout<<"dzielnik jest "<<tab[i]<<std::endl;
        passedDzielniki++;
      }
    }
    return passedDzielniki;
  }

  int main(){
    int numOfdzielniki = 0;
    std::cin >> numOfdzielniki;
    int * dzielniki = new int[numOfdzielniki];
    int temp = numOfdzielniki;
    int index = 0;
    while(temp != 0){
      temp--;
      int number = 0;
      std::cin >> number;
      dzielniki[index] = number ;
      index++;
    }

    int numOfKandydaci = 0;
    std::cin >> numOfKandydaci;
    while(numOfKandydaci != 0){
      int kandydatNumber = 0;
      std::cin >> kandydatNumber;
      std::cout << checkCandidate(dzielniki, numOfdzielniki, kandydatNumber);
      numOfKandydaci--;
    }
  }
