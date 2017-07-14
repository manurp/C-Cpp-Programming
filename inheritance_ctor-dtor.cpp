#include <iostream>
using namespace std;

class B {
protected:	int data_;
public:
	B(int d=0):data_(d) {cout<<"B::B B(int) "<<data_<<endl;}
	~B() {cout<<"B::~B "<<data_<<endl;}
};

class D : public B {
	int info_;
public:
	D(int d,int i):B(d),info_(i) {cout<<"D::D D(int,int) "<<data_<<", "<<info_<<endl;}
	D(int i):info_(i) {cout<<"D::D D(int) "<<data_<<", "<<info_<<endl;}
	~D() {cout<<"D::~D "<<data_<<", "<<info_<<endl; }
};

int main()
{
	B b(1);
	D d1(2,3);
	D d2(4);
	return 0;
}
