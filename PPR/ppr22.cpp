#include <iostream>
#include <string>
#include <vector>

void Sortowanie( std::string tab[], int size )
{
    for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if(tab[j] > tab[j +1])
                 swap( tab[ j ], tab[ j + 1 ] );

        }
    }
}

int main(){
  int numOfTests = 0;
  std::cin >> numOfTests;
  int temp = numOfTests;
  int index = 0;
  std::string *tab = new std::string[numOfTests];
  while(temp != 0){
    std::string input;
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
