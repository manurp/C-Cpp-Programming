#include<iostream>
using namespace std;
void swap(int&,int&);

int main()
{
	int a=10,b=15;
	cout<<"a = "<<a<<" b = "<<b<<" to swap\n";
	swap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<" after swap\n";

	return 0;
}

void swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}