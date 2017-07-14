#include <iostream>
using namespace std;

class Engine
{
public:
    Engine(int numCylinders){}

    void start() {cout<<"Engine started\n";}
};

class Car : private Engine
{
public:
    Car():Engine(8){}

    using Engine::start;
};

int main()
{
    Car c;
    c.start();

    return 0;
}
