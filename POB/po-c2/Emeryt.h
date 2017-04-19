#include "Osoba.h"
class Emeryt : public Osoba
{
private:
    float emerytura;
    float oprocentowanie;
public:
    Student(char* nazwisko, char* plec) : Osoba(nazwisko, plec), oprocentowanie(20)
    {    }
    float podajStypendium();
    void ustawStypendium(float stypendium);
    float dochod();
};
