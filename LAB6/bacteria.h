#ifndef bacteria_h
#define bacteria_h
#include "organism.h"
#include "gene_utils.h"

class Bacteria : public Organism {
public:
    using Organism::Organism; //Bacteria(std::string name, DNA dna):Organism(name, dna){}
    Organism* reproduce(Organism* organism = nullptr) override{
        Bacteria *tmp = new Bacteria(organismName, organismDNA); // tworzymy nowy obiekt
        tmp->organismDNA = mutation(organismDNA); // wywolujemy funcje mutation
        return tmp; // zwracamy obiekt
    }


};


#endif