#ifndef utils_h
#define utils_h
#include <vector>
#include <iostream>


class Coordinates {
protected:
    std::vector<double> coord;
public:
    Coordinates():coord{0.0, 0.0}{}
    Coordinates(const double dl, const double sz): coord{dl, sz} {}  
    Coordinates(const std::vector<double> vec){
        coord = vec;
    }
    Coordinates& operator+=(const Coordinates& tmp){
        coord[0]+=tmp.coord[0];
        coord[1]+=tmp.coord[1];
        return *this;
    }
    Coordinates& operator-=(const Coordinates& tmp){
        coord[0]-=tmp.coord[0];
        coord[1]-=tmp.coord[1];
        return *this;
    }
    // std::vector<double> operator-(const Coordinates &tmp) const{ //1 sposob
    //    std::vector<double> a = coord;
    //    a[0] -= tmp.coord[0];
    //    a[1] -=tmp.coord[1];
    //    return a;    
    // }
    operator std::vector<double>() const {return coord;} // 2sposob
    friend Coordinates operator-(const Coordinates& cr1, const Coordinates& cr2); // 2sposob
    friend std::ostream& operator<<(std::ostream &out, const Coordinates &tmp);
};

Coordinates operator-(const Coordinates& cr1, const Coordinates& cr2){
    Coordinates tmp(cr1.coord);
    tmp-=cr2;
    return tmp;
}

std::ostream& operator<<(std::ostream &out, const Coordinates &tmp){
        out<<"( ";
        for(auto n : tmp.coord){
            out<<n<<" ";
        }
        out<<" )";
        return out;
    } 



#endif