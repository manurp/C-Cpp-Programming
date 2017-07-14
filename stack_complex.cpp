#include<iostream>
using namespace std;

class Stack
{
    public:
    char data[100]; int top_=-1;

    bool empty()
    {
        return top_==-1;
    }

    char top(){return data[top_];}
    void push(char x){data[++top_]=x;}
    void pop(){--top_;}
};

int main()
{
    Stack s;s.top_=-1;
    char str[10]="ABCDEFGHI";

    for(int i=0;i<9;i++)
    s.push(str[i]);

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
