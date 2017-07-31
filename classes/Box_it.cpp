#include<bits/stdc++.h> //Includes all standard library

using namespace std;

//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box
{
    int l, b, h;
public:
    Box():l(0),b(0),h(0){}
    Box(int length, int breadth, int height):l(length), b(breadth), h(height){}
    Box(const Box& b):l(b.l),b(b.b),h(b.h){}
    int getLength() {
        return l;
    }
    int getBreadth() {
        return b;
    }
    int getHeight() {
        return h;
    }
    long long CalculateVolume() {
        return static_cast<long long>(l)*b*h; //If the product is really long
    }
    friend bool operator < (const Box& b1, const Box& b2) {
        if (b1.l < b2.l) return true;
        if(b1.b < b2.b && b1.l==b2.l) return true;
        if(b1.h < b2.h && b1.b==b2.b && b1.l==b2.l) return true;
        return false;
    }
    friend ostream& operator << (ostream& os, const Box& b) {
        os << b.l<<" "<<b.b<<" "<<b.h;
        return os;
    }
    ~Box(){}

};
void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
