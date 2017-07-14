#include<stdio.h>

#define LIFE 1
#define AUTO 2
#define HOME 3

struct addr{
char street[50];
char city[10];
char state[3];
char zip[7];
};
struct date {
int month;
int day;
int year;
};
struct policy {
int polnumber;
char name[30];
struct addr address;
int amout;
float premium;
int kind;
union {
struct {
char beneficiary[30];
struct date birthday;
}life;
struct {
int autodeduct;
char license[10];
char state[3];
char model[15];
int year;
} auto_;
struct {
int homededuct;
int yearbuilt;
}home;
}policyinfo;
};

int main()
{
    struct policy p={125,"Manoj",{"first st","mysore","ka","571105"},15000,390,1};//,{{"manu",{4,17,1997}},{10,"1789","ka","ka45",2015},{20,2013}}};
    p.policyinfo.life.birthday.month= 4;// = {"manu",{4,17,1997}};// = {{"manu",{4,17,1997}},{10,"1789","ka","ka45",2015},{20,2013}};
}
