#include <iostream>
using namespace std;

class A {
public:
	void f() {cout<<"A::f()\n";}
	virtual void g() {cout<<"A::g()\n";}
	void h() {cout<<"A::h()\n";}
};

class B : public A{
public:
	void f() {cout<<"B::f()\n";}
	void g() {cout<<"B::g()\n";}
	virtual void h() {cout<<"B::h()\n";}
};

class C: public B
{
public:
	void f() {cout<<"C::f()\n";}
	void g() {cout<<"C::g()\n";}
	void h() {cout<<"C::h()\n";}
};

int main()
{
	B *q = new C;
	A *p = q;

	p->f();
	p->g();
	p->h();

	q->f();
	q->g();
	q->h();
	return 0;
}
