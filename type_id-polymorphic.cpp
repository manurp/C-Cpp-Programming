#include <iostream>
#include <typeinfo>
using namespace std;

class A {
public:
	virtual ~A() {}
};

class B: public A {};

int main() {
	A a; B b;
	A* pA; B* pB;

	cout<<typeid(a).name()<<" : "<<typeid(b).name()<<endl<<endl;

	pA = &a; pB = &b;
	cout<<typeid(pA).name()<<" : "<<typeid(*pA).name()<<endl;
	cout<<typeid(pB).name()<<" : "<<typeid(*pB).name()<<endl<<endl;

	pA = pB;
	cout<<typeid(pA).name()<<" : "<<typeid(*pA).name()<<"\n\n";

	A& ra = a; A& rb = b;
	cout<<typeid(ra).name()<<" : "<<typeid(rb).name()<<"\n\n";

    A* pA1 = new A;

    cout<<typeid(pA1).name()<<" : "<<typeid(*pA1).name()<<"\n\n";
	delete pA1;
	try {
		cout<<typeid(pA1).name()<<endl;
		cout<<typeid(*pA1).name()<<endl; //Expected to throw bad_typeid error
	}
	catch(const bad_typeid& e) {
		cout<<"Caught "<<e.what()<<endl;
	}
    cout<<"\n";
	pB = 0;
	try {
		cout<<typeid(pB).name()<<endl;
		cout<<typeid(*pB).name()<<endl;
	}
	catch(const bad_typeid& e) {
		cout<<"Caught "<<e.what()<<endl;
	}

	return 0;
}
