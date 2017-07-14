#include<iostream>
#include<stack>
using namespace std;

int main()
{
	char str[]={'1','2','3','*','+','4','-'};
	stack<int> s;
	int i,op1,op2;

	for(i=0;i<7;i++){
		char ch=str[i];
		if(isdigit(ch)) s.push(ch-'0');
		else{
			op2=s.top();s.pop();
			op1=s.top();s.pop();
			switch(ch){
				case '+':s.push(op1+op2);break;
				case '-':s.push(op1-op2);break;
				case '*':s.push(op1*op2);break;
				case '/':s.push(op1/op2);break;
			}
		}
	}

	cout<<"Evaluation "<<s.top()<<endl;

	return 0;
}