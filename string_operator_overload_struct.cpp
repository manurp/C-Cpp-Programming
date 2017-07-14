#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct _String
{
    char* str_;
    //size_t len_;
}String;

String operator+(const String& s1,const String& s2)
{
    String s3;
    s3.str_ =(char *)malloc(strlen(s1.str_)+strlen(s2.str_)+1);
    strcpy(s3.str_,s1.str_);
    strcat(s3.str_,s2.str_);
    return s3;
}

int main()
{
    String s;
    s.str_="Manoj ";
    String s1;
    s1.str_="Poojari";
    String s2=s+s1;
    cout<<s2.str_;

}
