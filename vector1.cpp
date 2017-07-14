#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int count,sum=0;
	vector<int> arr;

	cout<<"Enter the size: ";
	cin>>count;

	arr.resize(count);

	for(int i=0;i<arr.size();i++){
		arr[i]=i;
		sum+=i;
	}

	cout<<"Array sum is : "<<sum<<"\n";

	return 0;

}