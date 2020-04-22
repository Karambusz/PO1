#ifndef myclass_h
#define myclass_h
#include <iostream>
#include <string>
#include "weapon.h"
#include "terrorist.h"

class Terrorist1 : public Terrorist, public Knife, public Rifle {
public:
    using Terrorist::Terrorist; // klasa pochodna ma te same argumenty w konstruktorze, wiec mozemy odziedziczyc konstruktor
    void what() const override {
        print({Knife::name, Rifle::name}); // korzystamy z operatoru zakresu aby dostac sie do zmiennych klasy Knife i Rifle
    }
    void attack() const override {
        Knife::cut(); // korzystamy z operatoru zakresu aby dostac sie do funkcji 
        Rifle::shoot();// korzystamy z operatoru zakresu aby dostac sie do funkcji 
    }
};

class Terrorist2 : public Terrorist, public Axe, public Bomb {
public:
    using Terrorist::Terrorist; // klasa pochodna ma te same argumenty w konstruktorze, wiec mozemy odziedziczyc konstruktor
    void what() const override {
        print({Axe::name, Bomb::name}); // korzystamy z operatoru zakresu aby dostac sie do zmiennych klasy Axe i Bomb
    }
    void attack() const override {
        Axe::chop();// korzystamy z operatoru zakresu aby dostac sie do funkcji 
        Bomb::explode();// korzystamy z operatoru zakresu aby dostac sie do funkcji 
    }
};

class Safety : public Terrorist {
private:
    Terrorist *_wsk;
    bool status; // zmienna okresla status ataki (true - ataka dziala, false - nie)
public:
    Safety(Terrorist* wsk):_wsk(wsk){
        status = true;
    }
    Safety(const std::unique_ptr<Terrorist> &uniq): _wsk(uniq.get()){  // za pomoca funkcji get zwracamy pointer i przypisujemy do naszej zmiennej
        status = true;
    }
    void what() const override{_wsk->what();}
    void attack() const override{
        if(status) //jezeli status true - ataka dziala
            _wsk->attack();
        
    }
    void apply_safety_measures(){status = false;} // funkcja ustawia status ataki na false
};


#endif