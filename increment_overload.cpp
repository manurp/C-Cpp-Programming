#include<iostream>
using namespace std;

class Myclass
{
	int data_;
public:
	Myclass(int d):data_(d){}//ctor
	Myclass(const Myclass& m):data_(m.data_){}//cctor
	~Myclass(){}//dtor
	Myclass& operator++()
	{
		++data_;
		return *this;
	}
	Myclass operator++(int)
	{
		Myclass d(data_);
		++data_;
		return d;
	}
	void print()
	{
		cout<<data_<<endl;
	}

};

int main()
{
	Myclass d(5);
	d.print();
	++d;
	d.print();
	Myclass d1=d++;
	d1.print();
}
