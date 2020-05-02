#ifndef rover_h
#define rover_h
#include "utils.h"
#include <string>
#include <functional>

const double PI = 3.14;
const double promien = 3396200;


double operator"" _km ( long double km ){
    double distance = km*1000;
    return (distance / promien) * (180/PI);
}



typedef std::vector<std::function<std::vector<double>()>> Program;

class Rover{
protected:
    std::string name;
    Coordinates coordinates;
    bool online;
public:
    friend class RoverIface;
    Rover() = default;
    Rover(const std::string nazwa):name(nazwa) {
        online = false;
    }
    std::string get_name() const {
        return name;
    }
    Coordinates get_coordinates() const{
        return coordinates;
    }
    virtual void execute(const std::function< void() > &action_){
        if(online){
            action_();
        } else {
            std::cout<<"ERROR: Rover not linked to an interface."<<std::endl;
        }
    }
    
    virtual void drive(const Program& progr_){
        if(online){
            for(auto s : progr_){
                coordinates+=s();
                std::cout<<"Arriving at"<<coordinates<<std::endl;   
            }
        }
    }
};

namespace MarsRoutes{
    Program route1() {
       return { [](){return std::vector<double>{1.0,-1.0};},
        [](){return std::vector<double>{1.0,0.0};},
        [](){return std::vector<double>{1.0,-1.0};},
       };      
    }
    Program go_to(Coordinates coor1, Coordinates coor2){
        return {[&coor1, &coor2](){return coor2-coor1;}};
    }    
} 


#endif