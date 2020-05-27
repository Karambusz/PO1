#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <type_traits>
#include <algorithm>
#include <numeric>



enum Bill{
    Zero_PLN = 0,
    Ten_PLN = 10,
    Twenty_PLN = 20,
    Fifty_PLN = 50,
    Hundred_PLN = 100
    
};

class WaterContainer{
private:
    double size;
    double pojemnosc;
public:
    WaterContainer(const double obj):size(obj) {}
    void put(const double obj){
        if(obj > size){
            std::string info = "Error: Container too small.";
            throw info;
        } else{
            pojemnosc = obj;
        }
    }
    double get() const{return pojemnosc;}
    void clean(){
        pojemnosc = 0;
    }
    double operator+=(const WaterContainer &tmp){
        pojemnosc += tmp.pojemnosc;
        return pojemnosc;
    }
};




class Wallet{
private:  
    int size;
    std::vector<Bill> wal;
    std::map<Bill, std::string> mp;
public:
    Wallet(const int rozm):size(rozm) {
        mp[Ten_PLN] = "Ten";
        mp[Twenty_PLN] = "Twenty";
        mp[Fifty_PLN] = "Fifty";
        mp[Hundred_PLN] = "Hundred";
    }    
    void put(const std::vector<Bill> bills){
        int rozm = bills.size();
        if(rozm > size){
            std::string info = "Error: Wallet too small.";
            throw info;
        } else{
            wal = bills;
        }
    }
    std::string get() const{
        std::string wynik;
        if(wal.size() == 0){
            return "No bills";
        } 
        else {
            for(auto n : wal){
                wynik+=mp.at(n)+" ";
            }   
        } 
        return wynik;
    }
    void clean() {
        wal.clear();
    }
    std::vector<Bill> operator+=(const Wallet &tmp){
        std::vector<Bill> wynik;
        std::copy(tmp.wal.begin(), tmp.wal.end(), std::back_inserter(wynik));
        std::copy(wal.begin(), wal.end(), std::back_inserter(wynik));
        wal = wynik;
        return wal;
    }

};

template<typename T>
void move_to_container(T &obj1, T &obj2){
    put(obj1, obj1+=obj2);
    obj2.clean();
}

template<int index, typename T>
std::vector<T> replicate_container(T &obj){
    std::vector<T> tmp(index, obj);
    return tmp;
}



template<typename T1, typename T2>
void compare_container_type(const T1& a,const T2& b){
    if(std::is_same<T1, T2>::value)
       std::cout<<"The containers are of same type."<<std::endl;
    else
        std::cout<<"The containers are of different type."<<std::endl;
}



