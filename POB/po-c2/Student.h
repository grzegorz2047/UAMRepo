#include "Osoba.h"
class Student : public Osoba
{
private:
    float stypendium;
    float oprocentowanie;
public:
    Student(char* nazwisko, char* plec) : Osoba(nazwisko, plec), oprocentowanie(20)
    {    }
    float podajStypendium();
    void ustawStypendium(float stypendium);
    float dochod();
};
