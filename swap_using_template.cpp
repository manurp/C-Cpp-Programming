#include <iostream>
#include <complex>
using namespace std;

template <class T>
inline void mswap(T&i,T& j) {
	T temp=i;
	i=j;
	j=i;
}


int main()
{
	int i=5,j=10;
	double x=5.6,y=6.5;
	cout<<"Inputs: "<<i<<", "<<j<<endl;
	mswap(i,j);
	cout<<"Outputs: "<<i<<", "<<j<<endl;
	cout<<"Double inputs: "<<x<<", "<<y<<endl;
	mswap(x,y);
	cout<<"Double outputs: "<<x<<", "<<y<<endl;
	complex<double> r(2.4,3.5),s(3.4,6.7);
	cout<<"Complex inputs: "<<r<<", "<<s<<endl;
	mswap(r,s);
	cout<<"Complex outputs: "<<r<<", "<<s<<endl;

	return 0;
}
