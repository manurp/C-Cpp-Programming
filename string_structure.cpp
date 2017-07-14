#include<iostream>
#include<cstring>
using namespace std;

struct String
{
    char* str_;
    size_t len_;
};

void print(const String& s)
{cout<<s.str_<<" "<<s.len_<<endl;}

int main()
{
    String s;

    s.str_=strdup("manoj");
    s.len_=strlen(s.str_);

    print(s);

    return 0;
}
