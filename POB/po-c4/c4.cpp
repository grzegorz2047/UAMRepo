#include <iostream>
template<class T>
class Stos
{
public:
	Stos(Stos<T>& stos)
	{	
		std::cout << "Kopiujemy" << std::endl;
		top=NULL;
		copy(stos);
	}
	Stos()             { top=NULL; }
	~Stos()            { while(top!=NULL) { Elem* stary=top; top=top->poprz; delete stary; } }
	void push(T e)   { Elem* nowy=new Elem;  nowy->dane=e; nowy->poprz=top; top=nowy; }
	T  pop()         { T ret=top->dane; Elem* stary=top; top=top->poprz; delete stary; return ret; }
	int  empty()       { return top==NULL; }
	Stos<T> operator=(Stos<T> stos){
		while(top!=NULL) {
			Elem* stary=top; 
			top=top->poprz;
			delete stary;
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
	void copy(Stos<T>& stos){
		Stos<T> stos2;				
		Elem* elem = stos.top;		
		while(elem != NULL)
		{
			stos2.push(elem->dane);
			elem = elem->poprz;
		}
		while(!stos2.empty()){ //przywroc porzadek
			this->push(stos2.pop());
		}
	}
  struct Elem { T dane; Elem* poprz; };
  Elem* top;
};

main()
{
  Stos<int> stos;
  stos.push(2); stos.push(5); stos.push(3);
  Stos<int> stos2 (stos);
  Stos<int> stos3 = stos2;
  stos3 << 10 << 20 << 60 <<24;
  int zmienna, z2 = 0;
  (stos3 >> zmienna) >> z2;
  //std::cout << zmienna << " " << z2 << std::endl;
  Stos<double> stos4;
  stos4 << 55.435363464645645645;
  Stos<bool> stos5;
  stos5 << true << true << false;
  while(!stos3.empty())
    std::cout << stos3.pop() << std::endl;
}
