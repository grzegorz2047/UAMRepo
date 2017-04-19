#include "Student.h"

float Student::podajStypendium(){
    return stypendium;
}
void Student::ustawStypendium(float stypendium){
    stypendium = stypendium;
}
float Student::dochod(){
    return (podajStypendium() + (podajStypendium() * oprocentowanie)/100);
}
