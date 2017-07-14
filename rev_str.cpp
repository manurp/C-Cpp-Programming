#include<iostream>
//#include<stdio.h>
#include<cstring>
#include<stack>
using namespace std;

int main()
{
	char str[10]="ABCDE";
	stack<char> s;
	int i;

	for(i=0;i<strlen(str);i++)
	{
		s.push(str[i]);
	}

	cout<<"Reversed string: ";

	for(i=0;i<strlen(str);i++){
		cout<<s.top();
		s.pop();
	}
}