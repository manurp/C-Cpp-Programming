#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct _String{char* str;}String;

String operator+(const String &s1,const String& s2){
String s;
s.str=(char*)malloc(strlen(s1.str)+strlen(s2.str+1));
strcpy(s.str,s1.str);
strcat(s.str,s2.str);
return s;
}

int main()
{
    String fname,lname,name;
    fname.str=strdup("Manoj ");
    lname.str=strdup("Poojari");

    name=fname+lname;

    cout<<"First name: "<<fname.str<<endl;
    cout<<"Last name: "<<lname.str<<endl;
    cout<<"Full name: "<<name.str<<endl;

    return 0;
}
