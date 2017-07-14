#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

class String
{
public:
    char* str_;size_t len_;
    String(char * s):str_(strdup(s)),len_(strlen(str_)){cout<<"String ctor: ";print();}
    String(const String& s):str_(strdup(s.str_)),len_(s.len_){cout<<"String cctor: ";print();}
    ~String(){free(str_);cout<<"String dtor: ";print();}
    void print(){cout<<str_<<endl;}
};

void strToUpper(String a)
{
    for(int i=0;i<a.len_;i++) a.str_[i]=toupper(a.str_[i]);
    cout<<"strToUpper: ";a.print();
}

int main()
{
    String s="Manoj";
    strToUpper(s);

    return 0;
}
