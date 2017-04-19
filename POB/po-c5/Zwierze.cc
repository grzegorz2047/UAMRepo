#include <iostream>

#include "Zwierze.hh"

void Zwierze::nadaj_imie(std::string s)  { imie=s; }

void Zwierze::przedstaw_sie()
{
  std::cout << "Jestem " << imie << std::endl ;
}

