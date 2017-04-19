#include <iostream>
#include <math.h>

using namespace std;

int pitagC(int a, int b){
  return ceil(sqrt(pow(a,2) + pow(b,2)));
}

int main(){
  int tries = 0;
  cin>> tries;
  for(int i= 0; i < tries; i++ ){
    int a, b, c = 0;
    cin>>a>>b;
    c = pitagC(a,b);
    cout << c<< " ";

    double min = f;
    if(s < min){
      min = s;
    }
    if(t < min){
      min = t;
    }
    cout << min;

  }

}
