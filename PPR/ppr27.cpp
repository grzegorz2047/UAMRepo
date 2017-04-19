#include <iostream>

using namespace std;

int NWD(int a, int b)
{
    while(a!=b)
       if(a>b)
           a-=b; //lub a = a - b;
       else
           b-=a; //lub b = b-a
    return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
}

int NWD(int a, int b, int c, int d)
{

    int temp = NWD(NWD(a,b), c);
    return NWD(temp, d);
}
int NWW(int a, int b){
  return a/NWD(a, b)*b;
}
int NWW(int a, int b, int c, int d){
  return NWW(NWW(NWW(a,b),c),d);
}

int main(){
  int tries = 0;
  cin >> tries;

  for(int i = 0; i < tries; i++){
    int * tab = new int[4];
    for(int j = 0; j < 4; j++){
      cin >> tab[j];
    }
    int nww = 0;
    nww = NWW(tab[0], tab[1], tab[2], tab[3]);
    cout<<nww;
    delete [] tab;
  }

}
