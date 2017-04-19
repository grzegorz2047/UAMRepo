#include <iostream>

class Stos
{
public:
  	Stos(){
	 top = NULL; 
	}
	~Stos()            
	{ 
		while(top!=NULL) {
			Elem* stary=top; 
			top=top->poprz; 
			delete stary; 
		} 
	}	
	void push(int e)   
	{ 
		Elem* nowy=new Elem;
		nowy->dane=e; 
		nowy->poprz=top;
		top=nowy;
	}
	virtual int  pop()         
	{ 
		int ret=top->dane;
 		Elem* stary=top;
 		top=top->poprz; 
		delete stary;
 		return ret; 
	}
	int  empty()       
	{ 
		return top == NULL;
	}
	int rozmiarIter()
	{
		int rozmiar = 0;
		Elem* elem = top;
		while(elem != NULL)
		{
			elem = elem->poprz;
			rozmiar++;		
		}
		return rozmiar;
	}
	int rozmiarRekur()
	{
		return helpCountSizeRecurr(top);
	}
	protected:
	  struct Elem { int dane; Elem* poprz; };
		int helpCountSizeRecurr(Elem* elem)
		{
			
			if(elem != NULL)
				return 1 + (helpCountSizeRecurr(elem->poprz));
			else			
				return 0;
		}

	  Elem* top;
};


class LepszyStos : Stos
{
	LepszyStos() {
		rozmiar = 0;
	}
public: 
	int pop()         
	{ 
		
		if(top == NULL)
		{
			std::cout << "Stos jest pusty!" << std::endl;
			return -1;
		}
		rozmiar--;
		Stos::pop();
	}
	void push(int e){
		rozmiar++;
		Stos::push(e);
	}
	int pop2()         
	{ 
		
		if(top == NULL)
		{
			std::cout << "Nie powiodlo sie" << std::endl;
			return -1;
		}
		rozmiar--;
		Stos::pop();
		std::cout << "Powiodlo sie" << std::endl;
	}
private:
	int rozmiar;

};


main()
{
  Stos stos;
  stos.push(2); stos.push(5); stos.push(3);
  std::cout << "Rozmiar " << stos.rozmiarRekur() << std::endl;
  while(!stos.empty())
    std::cout << stos.pop() << std::endl;
}
