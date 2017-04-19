#include <iostream>


  int silniaWielokrotna(unsigned int n, unsigned int k){
    if(k > n && n>=0){
      return 1;
    }else if(n >= k){
        return n * silniaWielokrotna(n-k, k);
    }else {
      return n;
    }
  }

  int main(){
    int size = 0;
    int numOfTests = 0;
    int n = 0, k = 0;
    std::cin>>numOfTests;
    int * answers = new int[numOfTests];
    size = numOfTests;
    int index = 0;
    while (numOfTests != 0) {
      std::cin>>n;
      std::cin>>k;
      answers[index] = silniaWielokrotna(n, k);
      //std::cout<<answers[index]<<std::endl;
      index++;
      numOfTests--;
    }
    for(int i = 0; i <size;i++){
      std::cout<<answers[i]<<std::endl;
    }


  }
