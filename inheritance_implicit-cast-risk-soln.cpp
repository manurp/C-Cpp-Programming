#include <iostream>
using namespace std;

class B {
protected:
	int data_;
public:
    B(int d=0):data_(d){}
	friend ostream& operator<<(ostream& os,const B& b)
	{
		os<<b.data_<<endl;
		return os;
	}

};

class D:public B {
	int info_;
public:
    D(int d,int i):B(d),info_(i){}
    D(int i):info_(i){}
    friend ostream& operator<<(ostream& os,const D& d)
    {
        os<<d.data_<<" "<<d.info_<<endl;
        return os;
    }

};

int main()
{
	B b(0);
	D d(1,2);
	D d1(3);

	cout<<b;    cout<<d;	cout<<d1;

	return 0;
}
