#include <iostream>
#include <cstdlib>
using namespace std;

namespace my
{
	int abs(int n)
	{
		if(n<-128||n>127) return 0;
		if(n<0) return -n;
		return n;
	}
}

int main()
{
	cout<<abs(6)<<" "<<abs(-6)<<" "<<abs(177)<<endl;
	cout<<my::abs(6)<<" "<<my::abs(-6)<<" "<<my::abs(177)<<endl;
	return 0;
}