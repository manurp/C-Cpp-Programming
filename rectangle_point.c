#include<iostream>
using namespace std;

class Point
{
    int x_,y_;
public:
    Point(int x,int y):x_(x),y_(y)
    {
        cout<<"Point ctor: ";print();
    }
    ~Point(){cout<<"Point dtor: ";
    print();}
    void print(){cout<<"("<<x_<<", "<<y_<<")\n";}
};

class Rect
{
    Point TL_;
    Point BR_;
public:
    Rect(int tlx,int tly,int brx,int bry):TL_(tlx,tly),BR_(brx,bry)
    {
        cout<<"Rect ctor: ";print();
    }
    ~Rect(){cout<<"Rect dtor: ";print();}
    void print()
    {
        cout<<"[";TL_.print();cout<<" ";BR_.print();cout<<"]";
    }
};

int main()
{
    Rect r(0,2,5,7);

    cout<<endl;r.print();cout<<endl;
    cout<<endl;
    return 0;
}
