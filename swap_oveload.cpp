#include <iostream>
using namespace std;

inline void swap(int&i,int& j) {
	int temp=i;
	i=j;
	j=i;
}

inline void swap(double& i,double& j) {
	double temp = i;
	i = j;
	j = i;
}

int main()
{
	int i=5,j=10;
	double x=5.6,y=6.5;
	cout<<"Inputs: "<<i<<", "<<j<<endl;
	swap(i,j);
	cout<<"Outputs: "<<i<<", "<<j<<endl;
	cout<<"Double inputs: "<<x<<", "<<y<<endl;
	swap(x,y);
	cout<<"Double outputs: "<<x<<", "<<y<<endl;

	return 0;
}