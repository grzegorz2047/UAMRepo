#include "Osoba.h"
#include "Pracownik.h"

    float Pracownik::podajPensje(){
        return pensja;
    }
    void Pracownik::ustalPensje(float pensja){
        this->pensja = pensja;
    }
    float Pracownik::podajPremie(){
        return 20 * this->pensja / 100;
    }
    float Pracownik::dochod(){
        return ((this->pensja * 23/100) + (this->podajPremie() * 23/100));
    }

