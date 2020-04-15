#ifndef virus_h
#define virus_h
#include <string>
#include <ostream>
#include "gene_sequence.h"
#include <utility>



class Virus {
protected:
    std::string virusName;   
    GeneSeq *wskGen;
    int wiek;
public:
    Virus():virusName(""), wskGen(nullptr), wiek(0){}

    Virus(std::string name): virusName(name), wskGen(nullptr),wiek(0) {}

    std::string get_name() const{ return virusName;};

    GeneSeq* get_RNA() const{ return wskGen;}

    void set_RNA(const std::vector< Nucleotide > rna) {wskGen = new GeneSeq(rna);}

    int get_age() const { return wiek;}

    Virus(Virus &tmp) {
        virusName = tmp.virusName;
        wiek = 0;
        tmp.wiek++;
        if(tmp.wskGen){
        wskGen = new GeneSeq(tmp.wskGen->get_sequence());
        }
    }
    
    Virus &operator=(Virus &tmp){
        if(this == &tmp){
            return *this;
        }
        delete wskGen;
        virusName = tmp.virusName;
        wskGen = new GeneSeq(tmp.wskGen->get_sequence());
        wiek = tmp.wiek;
        
        return *this;
        
    }
    Virus &operator=(Virus &&tmp) {
        virusName = std::exchange(tmp.virusName, "");
        wiek = std::exchange(tmp.wiek, 0);
        delete wskGen;
        wskGen = std::move(tmp.wskGen);
        tmp.wskGen = nullptr;       
        return *this;
    }
    
    Virus(Virus &&tmp) {
        virusName = std::exchange(tmp.virusName, "");
        wiek = std::exchange(tmp.wiek, 0);
        wskGen = tmp.wskGen;
        tmp.wskGen = nullptr;
    }
    
    ~Virus() {
        if(wskGen){
            delete wskGen;
        }
    }
    
    
    
};



#endif