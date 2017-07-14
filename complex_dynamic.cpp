#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    private:double re_,im_;
    public:Complex(double re=0.0,double im=0.0):re_(re),im_(im)
    {
        cout<<" Ctor ( "<<re_<<", "<<im_<<" )\n";
    }
    ~Complex()
    {
       cout<<" Dtor ( "<<re_<<", "<<im_<<" )\n";
    }
    double norm()
    {
        return(sqrt(re_*re_+im_*im_));
    }
    void print()
    {
        cout<<"| "<<re_<<"+ j"<<im_<<" | ="<<norm()<<endl;
    }
};

Complex c(1.2,2);//Static(global)

int main()
{
    unsigned char buf[100];

    Complex *pc=new Complex (4.3,3.5);
    Complex *pac=new Complex [2];
    Complex *pbc=new (buf) Complex (1.2);

    (*pc).print();
    pac[0].print();
    pbc->print();

    delete pc;
    delete [] pac;
    pbc->~Complex();

    return 0;

}
