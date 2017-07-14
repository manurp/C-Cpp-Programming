#include <iostream>
using namespace std;

class B {};
class A {
public:
	A(int i=0) {
		cout<<"A::i\n";
	}
	A(const B&) {
		cout<<"A::B&\n";
	}
};

int main() {
	A a ; //calls A(int)
	B b;
	int i =5;

	a=b;
	a = static_cast<A>(b);

	a=i;
	a=static_cast<A>(i);

	return 0;
}
