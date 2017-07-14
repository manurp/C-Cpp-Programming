#include <iostream>
using namespace std;

class B1
{
protected:
	int i,data;
public:
	B1(int i,int d):i(i),data(d) {cout<<"B1::B1()\n";}
	void f(int) {cout<<"B1::f(int)\n";}
	void g() {cout<<"B1::g()\n";}
	~B1() {cout<<"B1::~B1()\n";
};

class B2
{protected:
	int j , int data;
public:
	B2(int j=0,data=0):j(j),data(data) {cout<<"B2::B2()\n";}
	~B2() {cout<<"B2::~B2()\n";}
	void f(int) {cout<<"B2::f(int)\n";}
	void g(int) {cout<<"B2::g(int)\n";}
};

class D:public B1,public B2
{
	int k;
public:
	//To access data use B1::data or B2::data
	D(int x,int y,int z):B1(x,y),k(z) {cout<<"D::D()\n";}
	~D() {cout<<"D::~D()\n";}
};

int main() {
	D d(1,2,3);

	d.f(5);
	d.g();
	d.g(3);

	return 0;
}