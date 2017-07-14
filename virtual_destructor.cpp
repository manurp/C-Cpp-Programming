#include <iostream>
using namespace std;

class B {
	int data_;
public:
	B(int d):data_(d) {cout<<"B()\n";}
	virtual ~B(){cout<<"~B()\n";}
	virtual void print(){cout<<data_;}
};

class D:public B {
	int *ptr_;
public:
	D(int d1,int d2):B(d1),ptr_(new int(d2)) {cout<<"D()\n";}
	~D(){cout<<"~D()\n";delete ptr_;}
	void print() {B::print(); cout<<" "<<*ptr_;}
};

int main()
{
	B* p = new B(5);
	B* q = new D(3,9);

	p->print(); cout<<endl;
	q->print(); cout<<endl;

    delete p;
	delete q;
}
