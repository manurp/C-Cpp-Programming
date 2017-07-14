#include<iostream>
//#include<stdio.h>
#include<cstring>
#include<cstdlib>
using namespace std;

void* operator new[](size_t os,char setv)
{
    void *t=operator new(os);
    memset(t,setv,os);
    return t;
}

void operator delete[](void *ss)
{
    operator delete(ss);
}

int main()
{

    char*p=new('#')char[10];
    cout<<"p= "<<(int)p<<endl;
    for(int k=0;k<10;++k)
    {
        cout<<p[k];
    }

    delete[]p;

    return 0;
}
