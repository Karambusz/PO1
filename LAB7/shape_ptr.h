#ifndef shape_ptr_h
#define shape_ptr_h
#include "shape.h"
#include <utility>

class Shape_ptr {
private:
    Shape *wsk;
public:
    ~Shape_ptr(){ // destrukotor 
        if(wsk){
            delete wsk;
        }
    }
    Shape_ptr(): wsk(nullptr){} // konstruktor zwykly
    Shape_ptr(Shape *tmp): wsk(tmp){}
    Shape &operator*(){return *wsk;}
    
    Shape_ptr &operator=(Shape_ptr &tmp){// operator prypisania, ktory do wskaznika obiektu this przupisuje wskaznik, a argument usuwa
        if(this == &tmp){
            return *this;
        }
        
        if(wsk){
        delete wsk;
        }
        std::swap(wsk, tmp.wsk);

        
        return *this;
    }
    // operator przypisania
     Shape_ptr &operator=(Shape *&tmp){
        wsk = tmp; // przypisuje oryginal tmp do obiektu this
        tmp = nullptr;
        return *this;
     }
    
    // operator konwersiji obiektu klasy Shape_ptr do bool
    operator bool() const{
        if(wsk){
            return true;
        } else{
            return false;
        }
    }
    
    
    
    
};

#endif