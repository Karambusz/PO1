#ifndef shape_h
#define shape_h
#include <vector>
#include <iostream>
#include <string>

class Shape{
protected:
    std::string _name; 
    std::vector <float> _vector;
public:
    Shape(const std::string name, const std::vector<float> vec): _name(name), _vector(vec){} // konstruktor przyjmuje jako argument imie obiektu i zbior parametrow
    virtual float area() const = 0; //czysta funkcja virtualna ktora ma liczyc pole figury
    virtual float circumference() const = 0; //czysta funkcja virtualna ktora ma liczyc obwod figury
    virtual ~Shape() = default;
    friend std::ostream& operator<<(std::ostream& o, const Shape &shape); 
};

std::ostream& operator<<(std::ostream& o, const Shape &shape) { // operator wypisywania obiektu klasy Shape
    o<<shape._name;
    return o;
}


class Circle : public Shape {
public:
    using Shape::Shape; // klasa pochodna ma te same argumenty w konstruktorze, wiec mozemy  odziedziczyc konstruktor
    float area() const override {return 3.14 * _vector[0]*_vector[0];} // liczymy pole koła
    float circumference()const override  {return 2 * 3.14 * _vector[0];} // liczymy obwod koła
};

class Rectangle : public Shape {
public:
    using Shape::Shape;// klasa pochodna ma te same argumenty w konstruktorze, wiec mozemy  odziedziczyc konstruktor
    float area()const override {return _vector[0] * _vector[1];} // liczymy pole prostokata
    float circumference()const override {return 2 * (_vector[0] + _vector[1]);} // liczymy obwod prostokata
};






#endif