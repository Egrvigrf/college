#include <iostream>
// 基类
class Vehicle
{
public:
    void move()
    {
        std::cout << "Vehicle moves." << std::endl;
    }
};

// 第一个派生类
class Car : virtual public Vehicle
{
public:
    // 重写基类的move函数
    void move()
    {
        std::cout << "Car moves." << std::endl;
    }
};

// 第二个派生类
class Airplane : virtual public Vehicle
{
public:
    // 重写基类的move函数
    void move()
    {
        std::cout << "Airplane moves." << std::endl;
    }
};

// 最终类
class FlyingCar : public Car, public Airplane
{
public:
    // FlyingCar类继承了两个基类，但由于使用了虚拟继承，这里不会产生二义性
    void move()
    {
        std::cout << "FlyingCar moves." << std::endl;
    }
};

int main()
{
    FlyingCar fc;
    fc.move(); // FlyingCar类中的move函数不会产生二义性
    return 0;
}
