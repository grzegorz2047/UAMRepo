#include <iostream>
#include <list>
using namespace std;
template<class T>
class Stos
{
public:
	Stos(Stos<T>& stos)
	{	
		std::cout << "Kopiujemy" << std::endl;
		copy(stos);
	}
	Stos()             { }
	~Stos()            { while(!lista.empty()) { lista.pop_back(); } }
	void push(T e)   { lista.push_back(e); }
	T pop() { 
		T value = lista.back();
		lista.pop_back();
		return value;
	}
	int  empty()       { return lista.empty(); }
	Stos<T> operator=(Stos<T> stos){
		while(!lista.empty()) { 
			lista.pop_back();
		}
		copy(stos);
	}
	Stos<T>& operator <<(T e){
		push(e);
		return *this;
	}
	Stos<T>& operator >>(T& e){
		e = pop();
		return *this;
	}
	void test(Stos stos){

	}
private:
	list<T> lista;
	void copy(Stos<T>& stos){
		Stos<T> stos2;					
		while(!stos.empty())
		{
			stos2.push(stos.pop());
		}
		while(!stos2.empty()){ //przywroc porzadek
			this->push(stos2.pop());
		}
	}
};

main()
{
  Stos<int> stos;
  stos.push(2); stos.push(5); stos.push(3);
  Stos<int> stos2 (stos);
  //Stos<int> stos3 = stos2;
  //stos3 << 10 << 20 << 60 <<24;
  //int zmienna, z2 = 0;
  //(stos3 >> zmienna) >> z2;
  //std::cout << zmienna << " " << z2 << std::endl;
  //Stos<double> stos4;
  //stos4 << 55.435363464645645645;
  //Stos<bool> stos5;
  //stos5 << true << true << false;
  while(!stos2.empty())
    std::cout << stos2.pop() << std::endl;
  return 0;
}
