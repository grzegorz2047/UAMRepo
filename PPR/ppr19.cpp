#include <iostream>
#include <string>

int countLetters(std::string text){
  int letters = 0;
  for(int i = 0; i < text.length(); i++){
    if((char) text[i] >=67 && (char) text[i] <=90 ){
      letters++;
    }else if((char) text[i] >=97 && (char) text[i] <=122 ){
      letters++;
    }
  }
  return letters;
}


int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  std::string * people = new std::string[numOfTests];
  int temp = numOfTests;
  int index = 0;
  string text = "";

  while(temp != 0){
    std::cin >> text;

  }
}
