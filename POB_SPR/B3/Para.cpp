#include <iostream>

using namespace std;
template<class T>
class Para {
	public:
		Para(T a, T b) : _pierwszy(a), _drugi(b) {}
		T pierwszy() {return _pierwszy;}
		T drugi() {return _drugi;}
	private:
		T _pierwszy, _drugi;
};

int main(){
	Para<int> test(1,2);
	cout << "Pierwszy= " << test.pierwszy() << " Drugi= " << test.drugi() << endl;
	Para<float> test2(1.3,2.2);
	cout << "Pierwszy= " << test2.pierwszy() << " Drugi= " << test2.drugi() << endl;
}
