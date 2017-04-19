#include <iostream>

  void dorzucKwiaty(int &iloscKwiatow, int &x) {
    iloscKwiatow += 1;
    x /= 2;
  }

  void dorzucLiscie(int &iloscLisci, int &x){
    x = 3*x +1;
    iloscLisci += 1;
  }

  void rytual(int &iloscLisci, int &iloscKwiatow, int &kroki, int &x){
    while (x != 1) {
      kroki++;
      //std::cout<<" "<<iloscLisci<<" "<<iloscKwiatow<<" "<<kroki<<" "<<x<<std::endl;
      if(x % 2 == 0){
        dorzucKwiaty(iloscKwiatow, x);
      }else{
        dorzucLiscie(iloscLisci, x);
      }
    }
  }


  int main(){
    int steps = 0;
    int x = 0;
    int iloscKwiatow = 0;
    int iloscLisci = 0;
    do{
      std::cin >> x;
      if(x != 0){
        rytual(iloscLisci, iloscKwiatow, steps, x);
        //std::cout<<"Tuz po: "<<iloscLisci<<" "<<iloscKwiatow<<" "<<steps<<" "<<x<<std::endl;

        if(steps<=15){
          std::cout<<"TAK"<<" "<<iloscKwiatow<<" "<<iloscLisci<<std::endl;
        }else{
          std::cout<<"NIE"<<std::endl;
        }
        steps = 0;
        iloscKwiatow = 0;
        iloscLisci = 0;
      }
    }
    while(x != 0);
  }
