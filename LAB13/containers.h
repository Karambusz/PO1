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
    friend double operator+=(const WaterContainer &tmp1,const WaterContainer &tmp2);
};
    
double operator+=(const WaterContainer &tmp1,const WaterContainer &tmp2){
    double wynik = 0.0;
    wynik = tmp1.pojemnosc + tmp2.pojemnosc;
    return wynik;
}



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
    friend std::vector<Bill> operator+=(const Wallet &tmp1, const Wallet &tmp2); 

};

std::vector<Bill> operator+=(const Wallet &tmp1, const Wallet &tmp2){
    std::vector<Bill> wynik;
    std::copy(tmp1.wal.begin(), tmp1.wal.end(), std::back_inserter(wynik));
    std::copy(tmp2.wal.begin(), tmp2.wal.end(), std::back_inserter(wynik));
    return wynik;
}

template<typename T>
void move_to_container(T &obj1, T &obj2){
    try{
        obj1.put(obj1+=obj2);
        obj2.clean();
    }
	catch (const std::string& info) {
		std::cout << ">> " << info << std::endl; }
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



