#include <iostream>
using namespace std;

class Point
{
    double x_,y_;
public:
    Point(double x=0.0,double y=0.0):x_(x),y_(y){}
 friend Point operator+ (const Point& p1,const Point& p2)
    {
        Point sum (p1.x_+p2.x_,p1.y_+p2.y_);
        return sum;
    }

    friend ostream& operator<< (ostream& os,const Point& p)
    {
        return os<<"( "<<p.x_<<", "<<p.y_<<" )";
    }
};


int main()
{
    Point a (1,2);
    Point b(2.5,6.3);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<"Sum = "<<a+b<<endl;
    return 0;
}
