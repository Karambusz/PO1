#ifndef human_h
#define human_h
#include <iostream>
#include <tuple>
#include <functional>
#include <string>
#include <vector>

const int minuta = 60;
const int godzina = 3600;
const int doba = 86400;
const int rok = 31536000;

typedef std::tuple<int,int,int,int,int> czas;

std::ostream& operator<<(std::ostream& out, const czas &tmp){
    out<<std::get<0>(tmp)<<"y:"<<std::get<1>(tmp)<<"d:"<<std::get<2>(tmp)<<"h:"<<std::get<3>(tmp)<<"m:"<<std::get<4>(tmp)<<"s";
    return out;
} 

czas operator+(const czas &a, const czas &b){
    auto tmp = std::make_tuple(std::get<0>(a) + std::get<0>(b),std::get<1>(a) + std::get<1>(b),std::get<2>(a) + std::get<2>(b),std::get<3>(a) + std::get<3>(b),std::get<4>(a) + std::get<4>(b) );
    return tmp;
}

czas operator"" _sec(unsigned long long int sec){
    unsigned long long int tmp = sec;
    int years = tmp/ rok;
    tmp%=rok;
    int days = tmp / doba;
    tmp%=doba;
    int hours = tmp/godzina;
    tmp%=godzina;
    int minutes = tmp/minuta;
    tmp%=minuta;
    return {years, days, hours, minutes, tmp};
}

czas operator"" _yrs(unsigned long long int yrs){
    int years = yrs;
    return {years, 0, 0, 0, 0};
}

unsigned long long int to_sec(const czas &tmp){
    unsigned long long int wynik = 0;
    wynik += std::get<0>(tmp) * rok;
    wynik += std::get<1>(tmp) * doba;
    wynik += std::get<2>(tmp) * godzina;
    wynik += std::get<3>(tmp) * minuta;
    wynik += std::get<4>(tmp);
    return wynik;
}

czas from_sec(unsigned long long int sec){
    unsigned long long int tmp = sec;
    int years = tmp/ rok;
    tmp%=rok;
    int days = tmp / doba;
    tmp%=doba;
    int hours = tmp/godzina;
    tmp%=godzina;
    int minutes = tmp/minuta;
    tmp%=minuta;
    return {years, days, hours, minutes, tmp};
}



class Human {
protected:
    std::string name;
    czas myTime;
public:
    Human() = default;
    Human(const std::string imie, const czas &tmp):name(imie),myTime(tmp){} 
    std::string get_name() const {return name;}
    czas get_age() const {return myTime;}
    void update_time(const czas &tmp){
        czas nowyWiek = myTime + tmp;
        myTime = nowyWiek;
    }
    
    
};




class Clone : public Human {
    static int licznik;
public:
    Clone(){licznik = 0;}
    Clone(const Human &tmp){
        name = tmp.get_name();
        myTime = tmp.get_age();
        name+="_";
        name+=std::to_string(++licznik);
        if(licznik == 2){
            licznik = 0;
        }
    }
};

int Clone::licznik;

#endif
