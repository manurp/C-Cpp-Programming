#include <iostream>
using namespace std;

class A {
	int i_;
public:
	A(int j):i_(j){}
	int get() const {return i_;}
	void set(int j) {i_=j;}
};

void print(char* str) {cout<<str<<endl;}

int main() {
	const char* name = "Manoj R Poojari";
	print(const_cast<char*>(name));

	const A a(1);
	cout<<a.get()<<endl;

	//a.set(5);

	const_cast<A&>(a).set(5);
	cout<<a.get()<<endl;

    ((A)a).set(2);
	cout<<a.get()<<endl;
	return 0;
}
