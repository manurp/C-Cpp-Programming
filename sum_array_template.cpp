#include <iostream>
using namespace std;

int const n = 40;

template<class summable>
summable sum(const summable data[],int size,summable s=0)
{
	for(int i=0;i<size;++i)
		s+=data[i];
	return s;
}

int main()
{
	double accum=0;
	double data[n];
	for(int i=0;i<n;i++)
		data[i]=i/2.2;
	accum=sum(data,n);
	cout<<accum<<endl;
}
