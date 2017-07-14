#include<iostream>
using namespace std;

namespace myNameSpace
{
	int mydata=10;
	void myFunc()
	{
		cout<<"Inside the function\n";
	}
	class myClass
	{
		int data;
	public:
		myClass(int d):data(d){}
		void display(){cout<<data<<endl;}
	};
}

int main()
{
	cout<<myNameSpace::mydata<<endl;
	myNameSpace::myFunc();
	myNameSpace::myClass obj1(5);
	obj1.display();
	return 0;
}