#ifndef coronavirus_h
#define coronavirus_h
#include "virus.h"

class CoronaVirus : public Virus {
private:
    std::string animalName;
public:
    CoronaVirus():Virus(){
        animalName = "";
    }
    CoronaVirus(std::string name, std::string animal, const std::vector< Nucleotide > vec):Virus(name){
        animalName = animal;
        set_RNA(vec);
    }
    std::string get_animal_host() const{
        return animalName;
    }
    
    CoronaVirus(CoronaVirus &tmp):Virus(tmp){}
    CoronaVirus(CoronaVirus &&tmp):Virus(std::move(tmp)){}
    
    CoronaVirus &operator=(CoronaVirus &tmp){
        (*this).Virus::operator=(tmp);
        return *this;
    }
    
    CoronaVirus &operator=(CoronaVirus &&tmp){
        (*this).Virus::operator=(std::move(tmp));
        return *this;
    }
  
    
    
    
};


#endif