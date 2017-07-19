#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Complex {
	double re_,im_;
public:
	Complex(double re, double im):re_(re),im_(im) {}
	Complex(const Complex& c):re_(c.re_),im_(c.im_) {}
	double norm() const {return sqrt(re_*re_+im_*im_);}
	friend bool operator>(Complex& c1, Complex& c2) {
		return c1.norm() > c2.norm();
	}
	friend ostream& operator<<(ostream& os,const Complex& c) {
		os<<c.re_<<" + j"<<c.im_;
		return os;
	}
};

template<class T>
T Max(T x,T y) {
	return x>y?x:y;
}
template<>
char* Max<char*>(char* x, char* y) {
	return strcmp(x,y)>0?x:y;
}

int main() {
	int a=3,b=5;
	double c=1.3,d=3.6;
	Complex c1(1.2,5.3),c2(3.2,4.5);
	//Complex c3 = c2;
	char* s1 = new char[6]; char* s2  = new char[6];
	strcpy(s1,"Hello"); strcpy(s2,"Bob");

	cout<<"Max of ints: "<<Max(a,b)<<endl;
	cout<<"Max of doubles: "<<Max(c,d)<<endl;
	cout<<"Max of Complex numbers: "<<Max(c1,c2)<<endl;
	cout<<"Max of strings: "<<Max(s1,s2)<<endl;

	return 0;
}
