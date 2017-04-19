#include <iostream>
#include <string>

int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  int * answers = new int[numOfTests];
  int temp = numOfTests;
  int index = 0;
  while(temp != 0){
    temp--;
    std::string word;
    std::cin >> word;
    std::string word2;
    word2.resize(word.length());
    int j = 0;
    for(int i = word.length()-1; i>=0; i--){
      word2[i] = word[j];
      j++;
    }
    if(word == word2){
      std::cout<<word<<"=="<<word2<<std::endl;
    }else{
      std::cout<<word<<"!="<<word2<<std::endl;

    }
    index++;
  }
}
