#include <iostream>
#include <string>

int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  std::string * people = new std::string[numOfTests];
  int temp = numOfTests;
  int index = 0;
  while(temp != 0){
    std::string person = "";
    std::cin >> person;
    temp--;
    people[index] = person;
    index++;
  }
  std::string suspect = "";
  std::cin >> suspect;
  int count = 0;
  for(int i = 0; i < numOfTests;i++){
    if(suspect == people[i]){
      count++;
    }
  }
  std::cout << count << std::endl;
}
