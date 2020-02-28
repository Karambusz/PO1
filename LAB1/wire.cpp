#include "wire.h"
#include <iostream>
#include <utility>


// Konstruktor wieloargumentowy 
QuantumWire::QuantumWire(double length, int size){
    _length = length;
    _size = size;
    particles = new bool [_size];
    for(int i = 0; i < _size; i++) {
        particles[i] = rand()%2;
    }
}

//operator << ktory pozwala wypisywac obiekty klasy
std::ostream &operator<<(std::ostream &o, const QuantumWire &K) {
    o<<"length: "<<K._length<<", ";
    o<<"quanta: ";
    for(int i = 0; i < K._size; i++) {
        o<<K.particles[i]<<" ";
    }
    return o;
}

//Konstruktor domyślny, który zeruje pola i wskaźniki
QuantumWire::QuantumWire() {
    _length = 0;
    _size = 0;
    particles = nullptr;
}

// Konstruktor kopiujacy
QuantumWire::QuantumWire(const QuantumWire &tmp) { 
    _length = tmp._length;
    _size = tmp._size;
    particles = new bool[_size];
    for(int i = 0; i < _size; i++) {
        particles[i] = tmp.particles[i];
    }
}

// konstruktor przenoszacy
QuantumWire::QuantumWire(QuantumWire &&tmp) {
    _length = std::exchange(tmp._length, 0);
    _size = std::exchange(tmp._size, 0);
    particles = tmp.particles;
    tmp.particles = nullptr;
}

// destruktor, zwalnia pamiec 
QuantumWire::~QuantumWire() {
    if(particles) {
        delete [] particles;
    }
}

// operator mnozenia, ktory pozawala mnozyc liczbe przez obiekt klasy
QuantumWire operator*(double a, const QuantumWire &tmp) {
    QuantumWire nowy(tmp);
    nowy*=a;
    return nowy;
}

// operator mnozenia, ktory pozawala mnozyc obiekt klasy przez liczbe
QuantumWire operator*(const QuantumWire &tmp, double a) {
    QuantumWire nowy(tmp);
    nowy*=a;
    return nowy;
}
// operator mnozenia, ktory pozwala mnozyc dlugosc drutu przez liczbe x , 
// W wyniku powiększamy długość drutu x razy
QuantumWire & QuantumWire::operator*=(double a) {
    _length *= a;
    return *this; 
}

// operator !, ktory zmienia stan czastek na przeciwny
QuantumWire QuantumWire::operator!() {
    QuantumWire nowy;
    nowy._length = _length;
    nowy._size = _size;
    nowy.particles = new bool [_size];
    for(int i = 0; i < nowy._size; i++) {
        nowy.particles[i] = !particles[i];
    }
    return nowy;
}

// operator [], pozwala na wyświetlenie stanu i-tej cząstki
const bool & QuantumWire::operator[](unsigned i) const {
    return particles[i];
}

// operator (), ktory realizuje funkcje predykata
bool QuantumWire::operator()(const QuantumWire &tmp1, const QuantumWire &tmp2) {
    return tmp1._length > tmp2._length;
}

// operator przypisania kopiującego
QuantumWire & QuantumWire::operator=(const QuantumWire &tmp) {
        if(this ==&tmp){
        return *this;
    }
    delete [] particles;
    _length = tmp._length;
    _size = tmp._size;
    particles = new bool[_size];
    for(int i = 0; i < _size; i++){
        particles[i] = tmp.particles[i];
    }
    return *this;
}

// operator przypisania przenoszącego
QuantumWire & QuantumWire::operator=(QuantumWire &&tmp) {
    _length = std::exchange(tmp._length, 0);
    _size = std::exchange(tmp._size, 0);
    delete [] particles;
    particles = std::move(tmp.particles);
    tmp.particles=nullptr;
    return *this;
}
