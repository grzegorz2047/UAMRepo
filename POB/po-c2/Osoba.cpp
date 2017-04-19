#include "Osoba.h"

void Osoba::ustalDane(char* i, char* n, int r)
{
  ustalImie(i);
  ustalNazwisko(n);
  ustalRokUr(r);
}

Osoba::Osoba(char* i, char* n, int r)
{
  ustalDane(i,n,r);
}
Osoba::Osoba(char* nazwisko, char* plec)
{
  Osoba::ustalNazwisko(nazwisko);
  Osoba::ustalPlec(plec);
}
