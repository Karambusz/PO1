#ifndef organism_h
#define organism_h
#include <string>
#include "dna.h"
#include "virus.h"
#include <iostream>



class Organism {
protected:
    std::string organismName;
    DNA organismDNA; 
public:
    Organism(std::string name, DNA dna):organismName(name), organismDNA(dna){}
    std::string get_name() const{return organismName;}
    DNA get_dna() const{return organismDNA;}
    virtual Organism* reproduce(Organism* organism = nullptr) = 0;

    void operator <<(const Virus &virus) {
        
        //int losuj = rand()%2; 
        int losuj = 0; 
        int size = organismDNA[losuj].size();
        int sizeVirus = virus.get_RNA()->get_sequence().size();
        int mejsce = rand()%size;
        
        
        std::cout<<"Mejsce: "<<mejsce<<" vector: "<<losuj<<std::endl;
        std::vector< Nucleotide > a = organismDNA[losuj]; //kopiuje vector
        std::vector< Nucleotide > vir = virus.get_RNA()->get_sequence(); // kopiuje virus

        int licznik = 0;
        if( (mejsce + sizeVirus) < size) {
        for(int i = mejsce; i < size; i++) {
            a[i] = vir[licznik];
            licznik++;
            if(licznik >= sizeVirus)
                break;
        }
        } else
        {
            for(int i = mejsce; i < size; i++){
                a[i] = vir[licznik];
                licznik++;
                if(licznik >= sizeVirus)
                    break;
            }
            for(int i = 0; i < size; i++) {
                a[i] = vir[licznik];
                licznik++;
                if(licznik >= sizeVirus)
                    break;
            }   
        }

        if(losuj == 0) {
            organismDNA = DNA(a, organismDNA[1]);
        } else
        {
            organismDNA = DNA(organismDNA[0], a);
        }      
    }
    virtual ~Organism() = default;
};




#endif
