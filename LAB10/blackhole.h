#ifndef blackhole_h
#define blackhole_h
#include <string>
#include <iostream>

const double G = 6.67e-11;
const double M = 2e30;
const double c = 3e8;


class BlackHole {
private:
    std::string _name;
    double masaS;
    double _distance;
    double promien;
public:
    BlackHole() = default;
    BlackHole(const std::string nazwa, const double masa, const double dist):_name(nazwa), masaS(masa), _distance(dist){
        promien = ( 2 * G * M*masaS ) / (1000 * c * c); //liczymy promien
    }
    std::string getName() const{ // funkcja zwraca nazwe 
        return _name;
    }

    double get_mass() const {
        return masaS;
    }

    double get_Rh() const{
        return promien;
    }
    friend std::ostream& operator<<(std::ostream& out, const BlackHole &tmp);
    friend bool operator<(const BlackHole &x, const BlackHole &y);
    
};

std::ostream& operator<<(std::ostream& out, const BlackHole &tmp) { //operator wypisywania
    out<<tmp._name<<": M ="<<tmp.masaS<<" solar mass, Rh ="<<tmp.promien<<" km, dist="<<tmp._distance<<" pc"<<std::endl;
    return out;
}

bool operator<(const BlackHole &x, const BlackHole &y){ //operator <, potrzebny dla sort
    return x.masaS < y.masaS;
}


#endif