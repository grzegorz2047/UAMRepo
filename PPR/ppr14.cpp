#include <iostream>

 int sum = 0;

  double silniaKroliki(unsigned int n)  {
    if(n == 2){
      return 2;
    }
    if()
  }


  int main(){
    int numOfTests = 0;
    std::cin >> numOfTests;
    int * answers = new int[numOfTests];
    int temp = numOfTests;
    int index = 0;
    while(temp != 0){
      temp--;
      int number = 0;
      std::cin>> number;
      answers[index] = silniaKroliki(number);
      index++;
    }
    for(int i = 0; i < numOfTests; i++){
      std::cout<<answers[i]<<std::endl;
    }
  }
