#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int data[]={3,5,7,4,3};

	sort(data,data+5);

	for(int i=0;i<5;i++){
		cout<<data[i]<<" ";
	}

	return 0;
}