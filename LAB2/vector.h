#ifndef vector_h
#define vector_h

#include <iostream>


namespace MyStuff{
class vector {
private:
	int *tab;
	int _size;	
public:
	vector(int size);
	vector(const vector &);
	~vector();
	int &operator[](int i);
	friend std::ostream &operator<<(std::ostream &, const vector &);
	int size() { return _size;} // zwracaca wymiar wektora
	void push_back(int a);
	void pop_back();
	vector &operator=(const vector &);
	
	
	
};

}


#endif