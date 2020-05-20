#ifndef spacecraft_h
#define spacecraft_h

#include "human.h"

class Spacecraft {
private:
    std::vector<Human*> catal;
public:
    Spacecraft(const std::vector< Human* > tmp):catal(tmp){}
    void update_time(std::function<czas(const czas &time)> fun, const czas &time){
        
        for(auto &s : catal){
            s->update_time(fun(time));
        }   
    }
    Human operator[](const std::string name){
        for(auto s : catal){
            if(s->get_name() == name){
                return *s;
            }
        }
        return Human();
    }
    
    
};

#endif