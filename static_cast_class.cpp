#include <iostream>
using namespace std;

class A {};
class B:public A {};

int main() {
	A a;
	B b;

	A* p = &b;
//	B* q = &a; -->error

	p = static_cast<A*>(&b);
	B* q = static_cast<B*>(&a);

	return 0;
}
