#ifndef matrix_h
#define matrix_h
#include "vector.h"

#define max(X,Y) ((X)>(Y)? (X):(Y))  //makro max

namespace MyStuff{

class matrix {
private:
    int n; // liczba kolumn
    int m; // liczba wierszy
    vector **macierz;
public:
    matrix();
    matrix(const int, const int);
    matrix(const matrix &);
    matrix(matrix &&);
    matrix &operator=(const matrix &);
    matrix &operator=(matrix &&);
    friend std::ostream &operator<<(std::ostream &, const matrix &);
    vector &operator[](int) const;
    void fill(vector *, const int);
    void fill(const matrix &, const int, const int);
    friend matrix operator+(const matrix &, const matrix &);
    friend matrix operator*(const matrix &, const matrix &);
    int get_kolumn() const{return n;}
    int get_wierszy() const {return m;}
    void dtor();
    ~matrix();



};


















}

#endif 