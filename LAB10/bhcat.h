#ifndef bhcat_h
#define bhcat_h
#include <map>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include "blackhole.h"

double operator"" _pc ( long double pc ){
    double radius = pc * 3.1e13;
    return radius;   
}

class BHCatalogue {
private:
    std::map<std::string, BlackHole> catalog; //tworzymy katalog typu std::map
    std::map<int, std::string> mp; // std::map dla przychowywania i odczytu liczb rzymskich
    int index;
    const int size = 5;
public:
    BHCatalogue(){ // tworzymy mape dla liczb rzymskich
        mp[0] = "I.";
        mp[1] = "II.";
        mp[2] = "III.";
        mp[3] = "IV.";
        mp[4] = "V.";
        index = 0; // potrzebny dla odczytu 
    }
    void add(const BlackHole &tmp){
        if(index < 5){ //ograniczamy rozmiar mapy
        catalog[mp[index]] = tmp;
        index++;
        }
        else {
            std::cout<<">> Catalogue full. \""<<tmp.getName() <<"\" not added."<<std::endl;
        }
        
    }
    
   void add(const std::initializer_list<BlackHole> &l){
        for(auto s : l){
            if(index < 5){ //ograniczamy rozmiar mapy
            catalog[mp[index]] = s;
            index++;
            }
            else{
            std::cout<<">> Catalogue full. \""<<s.getName() <<"\" not added."<<std::endl;   
            }
        }       
    }
    
    BlackHole get(const std::string liczba) { //zwracamy obiekt klasy BlackHole
        return catalog[liczba];
    }
    
    std::map<std::string, BlackHole> get_map(){ // zwracamy nasz katalog
        return catalog;
    }
    
    std::vector<BlackHole> get_ordered_by_mass(){ // funkcja ktora zwraca vector typu BlackHole, odsortowanych wedlug masy
        std::vector<BlackHole> tmp; // tworzymy wektor
        for(int i = 0; i < size; i++){
            tmp.push_back(catalog[mp[i]]);   
        }
        sort(tmp.begin(), tmp.end()); // sortujemy za pomoca std::sort
        return tmp;
    }

    std::vector<BlackHole> get_custom(std::function<bool(const BlackHole &)> arg){
        std::vector<BlackHole> tmp; 
        for(int i = 0; i < size; i++){
            tmp.push_back(catalog[mp[i]]);   
        }
        std::vector<BlackHole> sorted;
        auto s = find_if(tmp.begin(), tmp.end(), arg);
        sorted.push_back(*s);
        while(s != tmp.end()){
            s = find_if(std::next(s), tmp.end(), arg);
            sorted.push_back(*s);
        }
        sorted.pop_back();
        return sorted;
    }
    
};



#endif