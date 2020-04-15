#include "gene_sequence.h"

// brak czasu na komentarze


std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_){
    for(auto n : seq_.chain) {
        out<<static_cast<char>(n)<<" ";
    }
    out<<std::endl;

    return out;
}