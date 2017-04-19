#include "Osoba.h"
class Rektor : public Pracownik
{
private:
    float dodatek;
    float oprocentowanie;
public:
    Student(char* nazwisko, char* plec) : Osoba(nazwisko, plec), oprocentowanie(20)
    {    }
    float podajStypendium();
    void ustawStypendium(float stypendium);
    float dochod();
};
