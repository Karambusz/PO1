#ifndef wire_h
#define wire_h

#include <iostream>

class QuantumWire{
private:
    double _length;
    bool *particles;
    int _size;
public:    
    QuantumWire(double, int);
    QuantumWire();
    ~QuantumWire();
    friend std::ostream &operator<<(std::ostream &, const QuantumWire &);
    friend QuantumWire operator*(double, const QuantumWire &);
    friend QuantumWire operator*(const QuantumWire & ,double);
    QuantumWire(const QuantumWire &);
    QuantumWire(QuantumWire &&);    
    QuantumWire &operator=(const QuantumWire &);
    QuantumWire &operator=(QuantumWire &&);
    QuantumWire &operator*=(double);
    QuantumWire operator!();
    const bool &operator[](unsigned) const;
    operator int() const{ return _size;} // funkcja konwertujaca obiekt do int'a
    bool operator()(const QuantumWire &, const QuantumWire &);    
};


#endif