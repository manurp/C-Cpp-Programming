#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class String
    {
        //public:
        char* str_;
        size_t len_;
public:
        String(char* s):str_(strdup(s)),len_(strlen(str_)){} //ctor
        String(const String& s):str_(strdup(s.str_)),len_(s.len_){}//cctor
        ~String(){free(str_);}
        String& operator=(const String& s){
        if(this!=&s)
        {
            free(str_);
            str_=strdup(s.str_);
            len_=s.len_;
        }
        return *this;
        }
        void display();
    };

    void String::display(){cout<<"("<<str_<<", "<<len_<<")\n";}

int main()
{
    String s="Manoj";
    s.display();
    String s1=s;
    s1=s1;
    s1.display();

}
