#ifndef sapper_board_h
#define sapper_board_h
#include "board.h"
#include <string>
#include <iostream>
#define MAX 20
#define MIN 5



class SapperBoard: public Board{
protected:
    int tab[3]; //[0] -x, [1] - y, [2] - mine
public:
    SapperBoard(int X, int Y, int mine) { // u mnie plansza zawsze jest kwadratem
        if(X < MIN && Y < MIN) {
            tab[0] = MIN;
            tab[1] = MIN;
        } else if(X > MAX && Y > MAX) {
            tab[0] = MAX;
            tab[1] = MAX;
        } else if ( (X < MIN && Y >= MIN) || (X > MAX && Y <= MAX) ) {
            tab[1] = Y;
            tab[0] = tab[1];
        } else if ( (X >= MIN && Y <= MIN) || (X <= MAX && Y > MAX) ) {
            tab[0] = X;
            tab[1] = tab[0];
        } else if (X >= MIN && (Y >= MIN && Y<=MAX) && X!=Y) {
            tab[0] = Y;
            tab[1] = Y;
        } else if(Y >= MIN && (X >= MIN && X<=MAX) && X!=Y) {
            tab[0] = X;
            tab[1] = X;
        }else {
            tab[0] = X;
            tab[1] = Y;
        }

        if(mine < 2) {
            tab[2] = 2;
        } else if(mine > tab[0] * tab[1]) {
            tab[2] = (tab[0] * tab[1]) / 3;
        } else {
            tab[2] = mine;
        }
    }

    int get_geometry(int k) const{
        if(k==0){
            return tab[0];
        } else if(k==1){
            return tab[1];
        } else if(k==2){
            return tab[2];
        } else
        {
            return 0;
        }
        
        
    }
    double get_params(int k) const{ // nie korzystam z funkcji get_params(), wiec zwraca po prostu 1.0
        return 1.0;
    }
};
#endif