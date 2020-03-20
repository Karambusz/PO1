#ifndef vector_h
#define vector_h


#include <iostream>


namespace MyStuff{
class vector {
private:
	int *tab;
	int _size;	
public:

	vector(); //konstruktor domyslny, poniewaz korzystamy z niego w main.cpp(110) 
	vector(int size);
	vector(const vector &);
	vector(vector &&);
	~vector();
	int &operator[](int i) const; 
	friend std::ostream &operator<<(std::ostream &, const vector &);
	int size() const { return _size;} // zwracaca wymiar wektora
	void push_back(int a);
	void pop_back();
	vector &operator=(const vector &);
	vector &operator=(vector &&);
	friend vector operator+(const vector &, const vector &); // operator dodawania 2 wektorow
	
	
	
};

}


#endif
