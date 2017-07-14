#include<iostream>
using namespace std;

int main()
{
	const int n=10;
	int m=9;
	const int *p=&m;
	cout<<n<<endl;
	//*p=10;
	cout<<*p<<endl;
}