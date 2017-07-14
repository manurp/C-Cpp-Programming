#include <iostream>
using namespace std;

class Engine {
public:
    Engine(int numCylinders){}
    void start() {cout<<"Engine started\n"; }
};

class Car {
Engine e_;
public:
    Car():e_(8){}
    void start() {e_.start();
    cout<<"Car can now run\n";}
};

int main(){
Car c;
c.start();
return 0;
}
