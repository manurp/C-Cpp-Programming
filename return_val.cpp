#include<iostream>
using namespace std;

int return_val(int &x)
{
	cout<<x<<"  "<<&x<<endl;
	return(x);
}

int main()
{
	int a=10;

	cout<<a<<"  "<<&a<<endl;
	const int &b=return_val(a);

	cout<<b<<"  "<<&b<<endl;
}