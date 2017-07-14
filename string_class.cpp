#include<iostream>
#include<cstring>
using namespace std;

class String
{
    char* str_;
    size_t len_;

public:
    String(char *s):str_(strdup(s)),len_(strlen(str_)){cout<<"Ctor called\n";}

    void print(){cout<<str_<<"  "<<len_<<endl;}

    ~String(){cout<<"Dtor called\n";}
};

int main()
{
    String s("Manoj");
    s.print();

    return 0;
}
