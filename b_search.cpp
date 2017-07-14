#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int data[]={1,2,3,4,5};
	int key=2;

	if(binary_search(data,data+5,key))
		cout<<"found!\n";
	else
		cout<<"not found\n";

	return 0;
}