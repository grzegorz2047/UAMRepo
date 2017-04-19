#include <iostream>
#include <string>



int doOperation(int num1, int num2, char sign){
  int answer = 0;
  if(sign == '+'){
    answer = num1 + num2;
  }
  else if(sign == '-'){
    answer = num1 - num2;
  }
  else if(sign == '*'){
    answer = num1 * num2;
  }
  return answer;
}

int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  int temp = numOfTests;
  int index = 0;

  while(temp != 0){
    int (*wskaznik)(int,int, char);
    wskaznik = doOperation;
    int num1, num2 = 0;
    char sign;
    std::cin >> num1 >> sign >> num2;
      if(sign == '+'){
        std::cout<<wskaznik(num1, num2, sign);
      }
      else if(sign == '-'){
        std::cout<<wskaznik(num1, num2, sign);
      }
      else if(sign == '*'){
        std::cout<<wskaznik(num1, num2, sign);
      }
          temp--;
    }




}
