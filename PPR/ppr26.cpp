#include <iostream>

using namespace std;

int NWD(int a, int b)
{
    while(a!=b){
      //cout<<"a "<<a<<" b "<<b<<endl;
       if(a>b)
           a-=b; //lub a = a - b;
       else
           b-=a; //lub b = b-a
    }
    return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
}

int main(){
  int tries = 0;
  cin >> tries;

  for(int i = 0; i < tries; i++){
    int * tab = new int[4];
    for(int j = 0; j < 4; j++){
      cin >> tab[j];
    }
    int z = 0;
    int nwd = tab[z];
    while(z != 3){
      nwd = NWD(nwd, tab[z+1] );

      z++;
    }
    cout<<nwd/;
    delete [] tab;
  }

}
