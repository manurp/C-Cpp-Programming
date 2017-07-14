#include<iostream>
using namespace std;

class Complex
{
	double re,im;
public:
	explicit Complex(double r=0.0, double i=0.0 ):re(r),im(i){}//ctor
	Complex(const Complex& c):re(c.re),im(c.im){}//ctor
	~Complex(){}//dtor
	void print(){cout<<re<<" +j"<<im<<endl;}

	friend Complex operator+(Complex& a,Complex& b)
	{return Complex(a.re+b.re,a.im+b.im);}

	friend Complex operator+(Complex& a,double d){
		Complex b(d);return(a+b);
	}

	friend Complex operator+(double d,Complex& b){
		Complex a(d);return(a+b);
	}

	friend ostream& operator<<(ostream& os,const Complex& c){
		os<<c.re<<" + j"<<c.im;
		return os;
	}

	friend istream& operator>>(istream& is,Complex& c){
		is>>c.re>>c.im;
		return is;
	}

};

int main()
{
	Complex c1(1.0,2);
	c1.print();
	Complex c2(c1);
	Complex c3=4.2+c1;
	Complex c4;
	Complex c5;
	cin>>c5>>c4;
	cout<<c5<<", "<<c4;

}
