#include <iostream>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double side)
    {
        this->side = side;
    }

    double area() override
    {
        return side * side;
    }

    // --> volume is not applicable for 2-d shape, therefore it is unnecessary to declare the volume here
    // --> and if it is not declare then also it is the violation of LSP 
    
    double volume() override 
    {
        throw logic_error("volume not applicable for square");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double side)
    {
        this->side = side;
    }

    double area() override
    {
        return 6 * side * side;
    }
    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    Shape* square = new Square(6);

    cout << "area of square: " << square->area() << endl;
    cout << "volume of square: " << square->volume() << endl;

    Shape* cube = new Cube(4);

    cout << "surface area of cube: " << cube->area() << endl;
    cout << "volume of cube: " << cube->volume() << endl;


    return 0;
}