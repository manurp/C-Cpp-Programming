#include <iostream>
using namespace std;

class Complex {
    int re_, im_;
public:
    Complex(int re=0, int im=0):re_(re), im_(im) {}
    Complex(const Complex& c):re_(c.re_), im_(c.im_) {}
    Complex operator+ (const Complex& c2) {
        Complex c3;
        c3.re_ = this->re_ + c2.re_;
        c3.im_ = this->im_ + c2.im_;
        return c3;
    }
    friend ostream& operator<<(ostream& os,const Complex& c) {
        os << c.re_ << " + j" << c.im_ << endl;
        return os;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(5, 8);
    Complex c3 = c1+c2;
    cout << c1+c2 << endl << c3 << endl;

    return 0;
}
