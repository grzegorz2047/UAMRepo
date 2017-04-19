#include "Osoba.h"
class Pracownik : public Osoba
{
    private:
      float pensja;
    public:
        Pracownik(char* nazwisko, char* plec) : Osoba(nazwisko, plec) {}
        float podajPensje();
        void ustalPensje(float pensja);
        float podajPremie();
        float dochod();
};
