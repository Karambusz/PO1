#ifndef dna_h
#define dna_h

#include "gene_sequence.h"
class DNA : public GeneSeq{
private:
    std::vector< Nucleotide > chain2;
public:
    // DNA (const std::vector< Nucleotide > v1, const std::vector< Nucleotide > v2):GeneSeq(v1){
    //       chain2 = v2;
    // }
    DNA(const GeneSeq &a, const GeneSeq &b):GeneSeq(a.get_sequence()){
        chain2 = b.get_sequence() ;
    }
    friend std::ostream& operator<<( std::ostream& out, const DNA& dna);   
    std::vector< Nucleotide > operator[](int i) const{
        if(i == 0) {return chain;}
        else{return chain2;}
    }

    std::vector< Nucleotide > get_chain(int i) const{
        if (i == 0){return chain;}
        else{return chain2;}      
    }
};

std::ostream& operator<<( std::ostream& out, const DNA& dna){
    for(auto n : dna.chain) {
        out<<static_cast<char>(n)<<" ";
    }
    out<<std::endl;
    int size = dna.chain2.size();
    for(int i = 0; i < size; i++){
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