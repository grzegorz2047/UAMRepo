
#pragma once

#include <string>
#include <iostream>

class Zwierze
{
private:
  std::string imie;

public:
  void nadaj_imie(std::string s);
  void przedstaw_sie();
  
  virtual void wydaj_dzwiek() = 0 ;
};
