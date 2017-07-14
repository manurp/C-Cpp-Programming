#include<iostream>
using namespace std;

char monthnames[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
char daynames[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

class Date
{
    enum Month{Jan=1,Feb,Mar,Apr,May,June,July,August,September,October,November,December};
    enum Day{Mon,Tue,Wed,Thu,Fri,Sat,Sun};
    typedef unsigned int UINT;
    UINT date_;Month month_;UINT year_;

public:
    Date(UINT d,UINT m,UINT y):date_(d),month_((Month)m),year_(y){cout<<"Ctor : ";print();}
    ~Date(){cout<<"Dtor : ";print();}
    void print(){cout<<date_<<"/"<<monthnames[month_-1]<<"/"<<year_<<endl;}
};

int main()
{
    Date d(17,04,1997);
    d.print();
    return 0;
}

