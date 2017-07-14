#include<iostream>
#include<stdlib.h>
using namespace std;

void* operator new(size_t n){//return type should be same,first parameter is fixed, can have multiple parms
cout<<"Overload new \n";
void*p=malloc(n);
return p;
}

void operator delete(void* p)//return type and first param is constant,usually 1 param.
{
    cout<<"Overload delete \n";
    free(p);
}

int main()
{
    int*p=new int;
    *p=30;
    cout<<"The value is: "<<*p<<endl;
    delete p;

    return 0;
}
