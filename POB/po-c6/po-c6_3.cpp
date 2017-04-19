#include <iostream>
#include <list>
#include <chrono>
#include <vector>
#include <list>
#include <iomanip> 

using namespace std;
using namespace std::chrono;


int main()
{
	int const size = 1000000;
	list<int> test1;
	vector<int> test2;
	//test2.resize(size);
	int tab[size];
	double sum = 0;
	auto start = high_resolution_clock::now();
	auto end = high_resolution_clock::now();
	sum+=std::chrono::duration<double, std::milli>(end-start).count();
	cout << "Margines bledu " << sum << endl;
	for(int n=0; n < size; ++n){
		auto t_start = high_resolution_clock::now();
		tab[n] = n;
    	auto t_end = high_resolution_clock::now();
    	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	}	
	cout << "Ogolny czas wstawiania do tablicy " << sum << endl;
	sum = 0;
	for(int n=0; n < size; ++n){
		auto t_start = high_resolution_clock::now();
		test1.push_back(n);
    	auto t_end = high_resolution_clock::now();
    	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	}	
	cout << "Ogolny czas wstawiania do listy z uzyciem push_back " << sum << endl;
	sum = 0;
	for(int n=0; n < size; ++n){
		auto t_start = high_resolution_clock::now();
		test1.push_front(n);
    	auto t_end = high_resolution_clock::now();
    	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	}	
	cout << "Ogolny czas wstawiania do listy z uzyciem push_front " << sum << endl;
	sum = 0;
	for(int n=0; n < size; ++n){
		auto t_start = high_resolution_clock::now();
		test2.push_back(n);
    	auto t_end = high_resolution_clock::now();
    	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	}	
	cout << "Ogolny Czas a wstawiania elementow do vectora " << sum << endl;
	sum = 0;
	auto t_start = high_resolution_clock::now();
	test1.pop_back();
	auto t_end = high_resolution_clock::now();
	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	cout << "Czas usuniecia ostatniego elem. z listy " << sum << endl;
	sum = 0;
	t_start = high_resolution_clock::now();
	test1.pop_front();
	t_end = high_resolution_clock::now();
	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	cout << "Czas usuniecia pierwszego elem. z listy  " << sum << endl;
	sum = 0;
	t_start = high_resolution_clock::now();
	list<int>::iterator it1;
	it1 = test1.begin();
	advance (it1,(test1.size()/2)); 
	test1.erase (it1);
	t_end = high_resolution_clock::now();
	sum+=std::chrono::duration<double, std::milli>(t_end-t_start).count();
	cout << "Czas usuniecia srodkowego elem. z listy  " << sum << endl;
	sum = 0;

}
