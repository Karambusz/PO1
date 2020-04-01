#ifndef dna_h
#define dna_h

#include "gene_sequence.h"
class DNA : public GeneSeq{
private:
    std::vector< Nucleotide > chain2;
public:
    DNA(const GeneSeq &a, const GeneSeq &b):GeneSeq(a.get_sequence()){
        chain2 = b.get_sequence() ;
    }
    friend std::ostream& operator<<( std::ostream& out, const DNA& dna);    
};

std::ostream& operator<<( std::ostream& out, const DNA& dna){
    for(auto n : dna.chain) {
        out<<static_cast<char>(n)<<" ";
    }
    out<<std::endl;
    for(auto n : dna.chain){
        out<<"|"<<" ";
    }
    out<<std::endl;
    for(auto n : dna.chain2) {
        out<<static_cast<char>(n)<<" ";
    }
    out<<std::endl;
    return out;
}


#endif