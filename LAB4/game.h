#ifndef game_h
#define game_h
#include "board.h"
#include "matrix.h"
#include <iostream>
#include <string>

class Game {
protected:
    std::string playerName;
    MyStuff::matrix _plansza;
public:
    virtual void new_player(std::string name) = 0;
    virtual void new_board(const Board& board) = 0;
    virtual void print_board() const = 0;
    virtual bool operator()(int x, int y) = 0;
    virtual ~Game(){}
};


#endif