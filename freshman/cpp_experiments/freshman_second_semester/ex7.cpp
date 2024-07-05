#include <iostream>
using namespace std;
class Vehicle
{
public:
    void move()
    {
        cout << "Vehicle moves." << endl;
    }
};
class Car : virtual public Vehicle
{
public:
    void move()
    {
        cout << "Car moves." << endl;
    }
};
class Airplane : virtual public Vehicle
{
public:
    void move()
    {
        cout << "Airplane moves." << endl;
    }
};
class FlyingCar : public Car, public Airplane
{
public:
    void move()
    {
        cout << "FlyingCar moves." << endl;
    }
};
int main()
{
    FlyingCar fc;
    fc.move();
    return 0;
}
