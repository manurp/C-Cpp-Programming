#include<iostream>
using namespace std;

typedef struct _Stack{
char data[100];
int top=-1;
}Stack;

bool empty(const Stack& s){
return(s.top==-1);
}

char top_(const Stack&s){return s.data[s.top];}

void push(Stack&s,char x){s.data[++(s.top)]=x;}

void pop(Stack&s){--(s.top);}

int main()
{
    Stack s;
    s.top=-1;
    char str[10]="ABCDE";

    for(int i=0;i<5;i++)push(s,str[i]);

    while(!empty(s))
    {
        cout<<top_(s);
        pop(s);
    }

    return 0;

}
