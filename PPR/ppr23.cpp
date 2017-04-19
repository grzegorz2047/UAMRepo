#include <iostream>
#include <string>
#include <vector>

void Sortowanie(int tab[], int size )
{
  for( int i = 0; i < size; i++ )
  {
    for( int j = 0; j < size - 1; j++ )
    {
        if(tab[j]> tab[j +1])
             swap( tab[ j ], tab[ j + 1 ] );

    }
  }
  for(int i = 0; i < size; i++){
    int test = tab[i];
    if(test == NULL){
      continue;
    }
    int count = 0;
    for(int j = 0; i < size; j++){
      if(test == tab[i]){
        tab[i] = NULL;
        count++;
      }
    }
    std::cout<<test;
  }
}

int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  int temp = numOfTests;
  int index = 0;
  std::int *tab = new int[numOfTests];
  while(temp != 0){
    int input;
    std::cin >> input;
    tab[index] = input;
    index++;
    temp--;
  }

  Sortowanie(tab, numOfTests);
  for(int i = 0; i < numOfTests; i++){
    std::cout<<tab[i]<<std::endl;
  }

}
