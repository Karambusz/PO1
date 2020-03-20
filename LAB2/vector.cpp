#include "vector.h"
#include <iostream>

namespace MyStuff{

	
//konstruktor zwykly
vector::vector(int size): tab(new int[size] {0}), _size(size) {}

// konstruktor kopiujacy
vector::vector(const vector &tmp) {
    _size = tmp._size;
    tab = new int[_size];
    for(int i = 0; i < _size; i++) {
        tab[i] = tmp.tab[i];
    }
}


// operator [] pozwalający na nadanie wartości oraz odczyt i-tego elementu
int &vector::operator[](int i) {
    return tab[i];
}

// operator drukowania do std-in <<
std::ostream &operator<<(std::ostream &o, const vector &tmp) {
    for(int i = 0; i < tmp._size; i++)
	o<<tmp.tab[i]<<" ";
    return o;
}

// metoda umieszczającą liczbę a na końcu wektora
void vector::push_back(int a) {
    int *tmp = new int[_size+1];
    for(int i = 0; i < _size; i++)
	tmp[i] = tab[i];
    delete [] tab;
    _size += 1;
    tmp[_size-1] = a;
    tab = tmp;
}

// metoda usuwającą ostatni element wektora
void vector::pop_back() {
    int *tmp = new int[_size-1];
    for(int i = 0; i < _size-1; i++)
	tmp[i] = tab[i];
    delete [] tab;
    _size -= 1;
    tab = tmp;
}

// operator przypisania kopiującego
vector & vector::operator=(const vector &tmp) {
    if(this ==&tmp){
        return *this;
    }
    delete [] tab;
    _size = tmp._size;
    tab = new int[_size];
    for(int i = 0; i < _size; i++){
        tab[i] = tmp.tab[i];
    }
    return *this;
}

// destruktor(zwalnia pamiec)
vector::~vector() {
    if(tab)
	delete [] tab;
}


}
