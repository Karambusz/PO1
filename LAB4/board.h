#ifndef board_h
#define board_h

class Board {
public:
virtual int get_geometry(int k) const = 0;
virtual double get_params(int k) const = 0;
virtual ~Board(){}
};


#endif