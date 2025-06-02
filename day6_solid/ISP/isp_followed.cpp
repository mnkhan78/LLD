#include <iostream>
using namespace std;

class TwoDShape
{
public:
    virtual double area() = 0;
};

class ThreeDShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDShape
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
};

class Cube : public ThreeDShape
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
    TwoDShape *square = new Square(6);
    cout << "area of square: " << square->area() << endl;

    ThreeDShape *cube = new Cube(4);
    cout << "surface area of cube: " << cube->area() << endl;
    cout << "volume of the cube: " << cube->volume() << endl;

    return 0;
}