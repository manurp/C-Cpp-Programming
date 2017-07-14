#include <iostream>
using namespace std;

class A
{
public:
	A(){cout<<"A ";}
	~A() {cout<<"~A \n";}

};

class B
{
public:
	B() {cout<<"B ";}
	~B() {cout<<"~B ";}

};

class C:public A
{
	B data_;
public:
	C() {cout<<"C\n";}
	~C() {cout<<"~C ";}
};

int main()
{
	C c;
	return 0;
}
