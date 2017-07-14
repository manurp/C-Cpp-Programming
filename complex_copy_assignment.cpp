#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    double re_,im_;
public:
    Complex(double re=0.0,double im=0.0):re_(re),im_(im){cout<<"ctor: ";print();}
    Complex(const Complex& c):re_(c.re_),im_(c.im_){cout<<"cctor: ";print();}
    Complex& operator=(const Complex& c)
    {
        re_=c.re_;im_=c.im_;cout<<"copy: ";print();return *this;
    }
    ~Complex(){cout<<"dtor: ";print();}
    double norm(){return sqrt(re_*re_+im_*im_);}
    void print(){cout<<"| "<<re_<<"+ j"<<im_<<" | ="<<norm()<<endl;}
};

int main()
{
    Complex c1(4.2,3.5),c2(8.2,7.3),c3(c2);
    c1.print();c2.print();c3.print();

    c2=c1;c2.print();
    c1=c2=c3;
    c1.print();c2.print();c3.print();

    return 0;
}
