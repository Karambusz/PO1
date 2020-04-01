#ifndef sapper_h
#define sapper_h
#include <string>
#include <iostream>
#include "game.h"
#include "board.h"
#include "sapper_board.h"
#include "matrix.h"
/////////komentarz//////////////
// w pliku main.cpp dostaje inne wyniki, przyczyna tego moze byc to,
// ze sposob losowania min jest inny niz w Pana, ale
// plik play.cpp dziala 
//
class Sapper: public Game {
protected:
    int mine;
    int iloscMin; 
    int licznikProb; // licze proby w operatorze ()
public:  
    Sapper(){
        playerName = "no-name";
        _plansza = MyStuff::matrix();
    }
    void new_board(const Board& board){
        _plansza = MyStuff::matrix(board.get_geometry(0), board.get_geometry(1));
        mine = -200;
        // losujemy miny
        iloscMin = board.get_geometry(2);
        licznikProb = 0; // zerujemy proby
        int licznikMin = 0;
        int losuj = 0;
        for(int i = 0; i < board.get_geometry(1); i++) {
            for(int j = 0; j < board.get_geometry(0); j++){
                losuj = rand()%3; // losujemy od 0-2, jezeli 0, to mina
                if(losuj == 0) {
                    _plansza[i][j] = mine; // -200 mina
                    licznikMin++;
                    if(licznikMin > board.get_geometry(2)){
                        _plansza[i][j] = -100; // -100 - brak miny
                    }
                } else {
                    _plansza[i][j] = -100;
                }
            }
        }
        // badamy macierz 
        int licznik = 0;
        for(int i = 0; i < board.get_geometry(1); i++) { // wierszy
            for(int j = 0; j < board.get_geometry(0); j++){ // kolumny
                licznik = 0;
                if(_plansza[i][j] == mine){continue;}
                if( ((i-1) < 0) && ((j-1) < 0) ){ //[0][0]
                    if(_plansza[i+1][j] == mine){licznik++;} // down
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i+1][j+1] == mine){licznik++;} // reverse diagonal right
                }
                else if( ( (j+1) == board.get_geometry(1)) && ((i-1) < 0) ) {// [0][y]
                    if(_plansza[i+1][j] == mine){licznik++;} // down
                    if(_plansza[i][j-1] == mine){licznik++;} // left
                    if(_plansza[i+1][j-1] == mine){licznik++;} // reverse diagonal left  
                }
                else if( ((i+1) == board.get_geometry(0)) && ((j+1) == board.get_geometry(1)) ){//[x][y]
                    if(_plansza[i][j-1] == mine){licznik++;} //left   
                    if(_plansza[i-1][j] == mine){licznik++;} // up
                    if(_plansza[i-1][j-1] == mine){licznik++;} // forward diagonal left
                }
                else if( ((i+1) == board.get_geometry(0)) && (j-1) < 0 ){//[x][0]
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i-1][j] == mine){licznik++;} // up
                    if(_plansza[i-1][j+1] == mine){licznik++;} // forward diagonal right
                }
                else if( ((j-1) < 0) &&  (i > 0 && i < board.get_geometry(0)-1) ){// [1][0] ... [x-1][0]
                    if(_plansza[i+1][j] == mine){licznik++;} // down 
                    if(_plansza[i+1][j+1] == mine){licznik++;} // reverse diagonal right
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i-1][j+1] == mine){licznik++;} // forward diagonal right
                    if(_plansza[i-1][j] == mine){licznik++;} // up
                }
                else if( ((i+1) >= board.get_geometry(0)) && (j > 0 && j < board.get_geometry(1)-1)){//[x][1] ... [x][y-1]
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i-1][j] == mine){licznik++;} // up
                    if(_plansza[i][j-1] == mine){licznik++;} //left 
                    if(_plansza[i-1][j-1] == mine){licznik++;} // forward diagonal left
                    if(_plansza[i-1][j+1] == mine){licznik++;} // forward diagonal right
                } 
                else if( ((j+1) >= board.get_geometry(1)) &&  (i > 0 && i < board.get_geometry(0)-1) ){//[1][y] ... [x-1][y]
                     if(_plansza[i][j-1] == mine){licznik++;} //left
                     if(_plansza[i-1][j] == mine){licznik++;} // up
                     if(_plansza[i-1][j-1] == mine){licznik++;} // forward diagonal left
                     if(_plansza[i+1][j-1] == mine){licznik++;} // reverse diagonal left [pr1]
                     if(_plansza[i+1][j] == mine){licznik++;} // down     [pr2]
                }
                else if( (j > 0 && j < board.get_geometry(1)-1) && (i-1) < 0 ) {// [0][1] .... [0][y-1]
                    if(_plansza[i][j-1] == mine){licznik++;} //left
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i+1][j+1] == mine){licznik++;} // reverse diagonal right
                    if(_plansza[i+1][j-1] == mine){licznik++;} // reverse diagonal left
                    if(_plansza[i+1][j] == mine){licznik++;} // down
                }
                 else { // middle
                    if(_plansza[i][j-1] == mine){licznik++;} //left  
                    if(_plansza[i-1][j-1] == mine){licznik++;} // forward diagonal left
                    if(_plansza[i-1][j] == mine){licznik++;} // up
                    if(_plansza[i-1][j+1] == mine){licznik++;} // forward diagonal right 
                    if(_plansza[i][j+1] == mine){licznik++;} // right
                    if(_plansza[i+1][j+1] == mine){licznik++;} // reverse diagonal right
                    if(_plansza[i+1][j] == mine){licznik++;} // down 
                    if(_plansza[i+1][j-1] == mine){licznik++;} // reverse diagonal left
                 }
                _plansza[i][j] += licznik;
            }
        }
     }
    void new_player(std::string name){playerName = name;} // zapisuje nazwe gracza

    void print_board() const{
        std::cout<<"\n";
        for(int i = 0; i < _plansza.get_wierszy(); i++) {
            for(int j = 0; j < _plansza.get_kolumn(); j++){
                if(_plansza[i][j] < 0){ // jezeli liczba ujemna to "*"
                    std::cout<<"* ";
                }else if(_plansza[i][j] >= 0){ // jezeli dodatnia to otwieramy "*"
                    std::cout<<_plansza[i][j]<<" ";
                }
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }

    // operator ktory wykonuje ruch na pole
    bool operator()(int x, int y){
        if( x < 0 || x >= _plansza.get_kolumn() || y < 0 || y >= _plansza.get_wierszy()){ // sprawdzamy zakres
            std::cout<<"out of range...."<<std::endl; 
            return true;           
        }
        _plansza[y][x] += 100; // dodajemy 100 do wybranego pola
        licznikProb++; // zwiekszamy ilosc
        std::cout<<"Ilosc min =     "<<iloscMin<<"    Licznik prob = "<<licznikProb<<std::endl;
        if(_plansza[y][x] == -100) { // jezeli po dodaniu pole rowne jest -100, to mina, wiec koniec gry
            std::cout<<"!!!   BOOOOM    !!!"<<std::endl<<"      Game Over      "<<std::endl; 
            return false;            
        }

        if(licznikProb == _plansza.get_kolumn() * _plansza.get_wierszy() - iloscMin){
            std::cout<<"WINNNNNNNNNNER!!!!!!!"<<std::endl;
            return false; 
        }
        if(_plansza[y][x]>=100){ // jezeli okno jest otwarte po raz drugi, to liczba wtedy bedzie >= 100, jezeli okno - nie mina
            std::cout<<"Pole juz otwarte, strzelaj w inne!"<<std::endl;
            _plansza[y][x]-=100; 
            licznikProb--; // jezeli okno jest otwarte po raz drugi, to zmniejszamy ilosc
            return true;
        }
        return true;
        
    }
};


#endif
