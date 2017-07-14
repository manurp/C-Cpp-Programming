#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class String
{
public:
    char *str_;
    size_t len_;
    String(const char* s):str_(strdup(s)),len_(strlen(str_)){}//ctor
    String(const String& s):str_(strdup(s.str_)),len_(s.len_){}//cctor
    String& operator=(const String& s)
    {
        if(this !=&s)
        {
            free(str_);
            str_=strdup(s.str_);
            len_=s.len_;
        }
        return *this;
    }
    ~String(){free(str_);}//dtor
    void print(){cout<<"( "<<str_<<": "<<len_<<")\n";}
};

int main()
{
    String s1="manu",s2="shamantha";
    s1.print();s2.print();
    s1=s2;s1.print();
    return 0;
}
