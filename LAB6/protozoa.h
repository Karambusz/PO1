#ifndef protozoa_h
#define protozoa_h
#include "bacteria.h"

class Protozoa : public Organism {
public:
    using Organism::Organism; //Protozoa(std::string name, DNA dna):Organism(name, dna);
    Organism* reproduce(Organism* organism = nullptr) override{
        if(organism->get_name() == this->organismName) {
        Protozoa *tmp = new Protozoa(organismName, organismDNA);
        tmp->organismDNA = mutation(DNA(this->get_dna()[0], organism->get_dna()[1]));
        return tmp;
        } else
        {
            return nullptr;
        }
        
    }
};


#endif