#include <iostream>
using namespace std;

class A {
public:
	virtual ~A() {}
};
class B:public A {};
class C {
public:
	virtual ~C() {};
};

int main() {
	A a; B b; C c;
	A* pA; B* pB; C* pC; void* pV;

	pB = &b; pA = dynamic_cast<A*>(pB); //Upcast
	cout<<pB<<" cast to "<<pB<<" valid"<<endl;

	pA = &b; pB = dynamic_cast<B*>(pA); //Downcast
	cout<<pA<<" cast to "<<pB<<" valid\n";

	pA = &a; pB = dynamic_cast<B*>(pA);
	cout<<pA<<" cast to "<<pB<<" invalid\n";

	pA = (A*)&c; pC = dynamic_cast<C*>(pA);
	cout<<pA<<" cast to "<<pC<<" invalid\n";

	pA = 0; pC = dynamic_cast<C*>(pA);
	cout<<pA<<" cast to "<<pC<<" invalid\n";

	pA = &a; pV = dynamic_cast<void*>(pA);
	cout<<pA<<" cast to "<<pV<<" valid\n";

	//pA = dynamic_cast<A*>(pV);  gives error

	return 0;
}
