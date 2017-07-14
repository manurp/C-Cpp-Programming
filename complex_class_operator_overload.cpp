#include<iostream>
using namespace std;

class Complex
{
    double re_,im_;
public:
    Complex(double r=0.0,double i=0.0):re_(r),im_(i){}//ctor
    Complex(const Complex& c):re_(c.re_),im_(c.im_){} //ctor
    ~Complex(){}//dtor
    Complex operator+(const Complex& c)
    {
        Complex r;
        r.re_=re_+c.re_;
        r.im_=im_+c.im_;
        return r;
    }
    void display()
    {
        cout<<re_<<" +j"<<im_<<endl;
    }
};

int main()
{
    Complex c1(1.2,4.6);
    Complex c2=c1;
    Complex c3=c1+c2;
    c3.display();
}
