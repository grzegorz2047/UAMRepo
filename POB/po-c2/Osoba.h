#include <string.h>
#ifndef __OSOBA_H__
#define __OSOBA_H__
class Osoba
{
 public:
  Osoba(char* nazwisko, char* plec);
  Osoba(char* i, char* n, int r);

  void ustalImie(char* i) { strcpy(imie,i); }
  void ustalNazwisko(char* n) { strcpy(nazwisko,n); }
  void ustalRokUr(int r) { rokur=r; }
  void ustalPlec(char* plec) { strcpy(this->plec,plec); }


  const char* podajImie() { return imie; }
  const char* podajNazwisko() { return nazwisko; }
  const char* podajPlec() { return plec;}
  int podajRokUr() { return rokur; }

  void ustalDane(char* i, char* n, int r);

 private:
  char imie[40];
  char nazwisko[40];
  char plec[20];
  int rokur;

};
#endif
