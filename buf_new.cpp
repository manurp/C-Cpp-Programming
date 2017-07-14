#include<iostream>
using namespace std;
int main()
{

    unsigned char buf[sizeof(int)*2];

    int*pInt=new (buf)int(5);
    int*qInt=new (buf+sizeof(int))int(6);

    int *pbuf=(int*)buf; int *qbuf=(int*)(buf+sizeof(int));

    cout<<"Buffer Address\tInteger Address\n";
    cout<<pbuf<<"\t"<<pInt<<endl;
    cout<<qbuf<<"\t"<<qInt<<endl;
    cout<<*pInt<<"\n"<<*qInt<<endl;

    int *r=new int(2);      //Dynamic allocation of memory;
    cout<<*r<<endl;
    delete r;

    //Array:Dynamically allocated;
    int* a=new int[3];
    a[0]=1,a[1]=3,a[2]=7;
    delete []a;
}
