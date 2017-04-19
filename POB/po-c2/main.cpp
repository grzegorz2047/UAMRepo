#include "Pracownik.h"
#include "Student.h"
#include "Osoba.h"
#include <string.h>
#include <iostream>


int main(){
  Student* student = new Student("Nowak","Mezczyzna");
  Pracownik* pracownik = new Pracownik("Adamska", "Kobieta");
  Osoba* osoba[2];
  osoba[0] = student;
  osoba[1] = pracownik;
  delete osoba[0];
  delete osoba[1];
}
