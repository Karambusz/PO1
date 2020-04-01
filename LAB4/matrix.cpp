#include "matrix.h"
#include <iostream>
#include <utility>


namespace MyStuff{


matrix::matrix():n(0), m(0), macierz(nullptr) {}

matrix::matrix(const int k, const int w):n(k), m(w),macierz(new vector *[m]) {
    for(int i = 0; i < m; i++)
        macierz[i] = new vector(n); // alokacja pamieci na kolumny, i wypelnianie macierzy zerami
}

matrix::matrix(const matrix &tmp):n(tmp.n), m(tmp.m),macierz (new vector *[m]){
    for(int i = 0; i < m; i++)
        macierz[i] = new vector(*tmp.macierz[i]);
}

matrix::matrix(matrix &&tmp): n(std::exchange(tmp.n, 0)), m(std::exchange(tmp.m, 0)), 
                              macierz(std::exchange(tmp.macierz, nullptr)) {}

matrix & matrix::operator=(const matrix &tmp) {
    if(this == &tmp)
        return *this;
    dtor();
    matrix temp(tmp.n, tmp.m);
    *this = temp;
    return *this;
}

matrix & matrix::operator=(matrix &&tmp) {
    if(this == &tmp)
        return *this;
    dtor();
    n = std::exchange(tmp.n, 0);
    m = std::exchange(tmp.m, 0);
    macierz = std::exchange(tmp.macierz, nullptr);
    return *this;
}

std::ostream &operator<<(std::ostream &o, const matrix &tmp) {
    for(int i = 0; i < tmp.m; i++) {
        o<<tmp.macierz[i][0]<<" "; // wypisuje i-ty wiersz macierzy
        o<<'\n';
    }
        o<<'\n';
    return o;
}

vector & matrix::operator[](int i) const{
    return macierz[i][0]; // zwracam i-ty wiersz macierzy
}

//metoda wypelniajaca macierz przy pomocy tablicy vector[],
void matrix::fill(vector *arr, const int y) {
    for(int i = 0; i < y; i++) {
        (*this)[i] = arr[i]; // korzystam z operatora [] klasy matrix, aby odniesc sie do okreslonego wiersza i nadac mu wartosc
    }
}
               // macierz, ktora dodaje   wierzy    kolumny 
void matrix::fill(const matrix& arr1, const int x, const int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            macierz[i]->operator[](j) += arr1.macierz[i]->operator[](j);
        }   // korzystam z operatora [] vectora, aby odniesc sie do okreslonego elementu i nadac mu wartosc
    }
}

matrix operator+(const matrix &m1, const matrix &m2) {
    int maxTempX = max(m1.n, m2.n); // wyliczam w ktorej macierzy jest wieksza liczba kolumn i wierzy 
    int maxTempY = max(m1.m, m2.m); 

    matrix temp = matrix(maxTempX, maxTempY); // tworzenia zerowej macierzy
    temp.fill(m1, m1.m, m1.n); // dodaje pierwsza macierz, korzystam z pomocniczej funkcji fill
    temp.fill(m2, m2.m, m2.n); // dodaje druga macierz
    //2sposob
    //for(int i = 0; i < m1.m; i++)
   // temp.macierz[i][0] = temp.macierz[i][0] + m1.macierz[i][0];
   // for(int i = 0; i < m2.m; i++)
   // temp.macierz[i][0] = temp.macierz[i][0] + m2.macierz[i][0]; 
   //3sposob
   //for(int i = 0; i < m1.m; i++)
   //temp[i] = temp[i] + m1[i];
  // for(int i = 0; i < m2.m; i++)
   //temp[i] = temp[i] + m2[i];

    return temp;
}

matrix operator*(const matrix &m1, const matrix &m2) {
    matrix iloczyn(m2.n, m1.m); // tworzenie macierzy n*m(mnozenia mozliwe, jezeli M1 jest wymiaru n*k , M2 - k*m)
    for(int i = 0; i < m1.m; i++) { // standardowy algorytm mnozenia macierzy
        for(int j = 0; j < m2.n; j++) {
            for(int k = 0; k < m1.n; k++) 
                iloczyn.macierz[i]->operator[](j) += m1.macierz[i]->operator[](k) * m2.macierz[k]->operator[](j);
        }       // korzystam z operatora [] vectora, aby odniesc sie do okreslonego elementu i nadac mu wartosc
    }
    return iloczyn;
}

void matrix::dtor() { // destruktor, zapisany jako funkcja void
    if(macierz) {     //  korzystam z niej w operatorze przypisania (kopiujący, przenoszący)
        for(int i = 0; i < m; i++)
            delete macierz[i];
        delete [] macierz;
    }
}

matrix::~matrix() {
    for(int i = 0; i < m; i++)
        delete macierz[i];
    delete [] macierz;
}

}

    // for(int i = 0; i < m1.m; i++) {
    //     for(int j = 0; j < m1.n; j++) {
    //         temp.macierz[i]->operator[](j) += m1.macierz[i]->operator[](j);
    //     }
    // }
    // for(int i = 0; i < m2.m; i++) {
    //     for(int j = 0; j < m2.n; j++) {
    //         temp.macierz[i]->operator[](j) += m2.macierz[i]->operator[](j);
    //     }
    // }