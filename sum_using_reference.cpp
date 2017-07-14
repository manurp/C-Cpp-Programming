#include <iostream>
using namespace std;

int const n = 40;

inline void sum(int &p,int n,int*d)
{
	for(int i=0;i<n;i++)
		p+=d[i];
}

int main()
{
	int accum=0;
	int *data = new int[n];
	for (int i=0;i<n;i++)
		data[i]=i;
	sum(accum,n,data);
	delete[] data;
	cout<<"Sum is "<<accum<<endl;
	return 0;
}
