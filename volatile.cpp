#include<iostream>
using namespace std;

int main()
{
	static volatile int i=10;
	while(i !=100){
		cout<<i<<endl;
	}
}