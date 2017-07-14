#include <iostream>
using namespace std;

class A
{
protected:
	A(){cout<<"A ";}
	~A() {cout<<"~A ";}

};

class B :public A
{
    //protected:
public: //if protected error!!
	B() {cout<<"B ";}
	~B() {cout<<"~B ";}

};

class C:private B
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
