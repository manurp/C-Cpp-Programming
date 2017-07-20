#include <iostream>
#include <cstring>
using namespace std;

template <class T> class Stack;             //Forward declaration

void reverseString(Stack<char>&,char*);

template <class T>							//Declaration
class Stack {
	T data_[100];
	int top_;
public:
	Stack():top_(-1){} ~Stack(){}

	void push(T d){data_[++top_] = d;}
	void pop(){--top_;}
	const T& top(){return data_[top_];}
	bool empty() const {return top_==-1;}
};

int main(int argc, char const *argv[])
{
	Stack<char> s;
	char* str = "ABCDE";

	reverseString(s,str);

	return 0;
}

void reverseString(Stack<char>&s,char* str) {
	for(unsigned int i=0;i<strlen(str);i++) s.push(str[i]);
        cout<<"Input string: "<<str<<endl;
		cout<<"Reversed string: ";
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
}
