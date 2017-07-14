#include <iostream>
using namespace std;

class A {
    int i_;
public:
    A(int i=0):i_(i){}
	operator int() {
		cout<<"A::operator int\n";
	}
};

class  B
{
public:
	operator A() {
		cout<<"B::operator A\n";
	}

};

int main(int argc, char const *argv[])
{
	A a;
	B b;
	int i =5;

	i=a;
	i = static_cast<int>(a);

	a=static_cast<A>(b);
	a=b;
	return 0;
}
