#include<iostream>
#include<vector>

using namespace std;

int main()

{
	int n,q,k;
	vector<vector<int> > arr;

	cin>>n>>q;
    int ans[q];
    arr.resize(n);

	for(int i=0;i<n;i++){
		cin>>k;
		arr[i].resize(k);
		for(int j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<q;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		ans[i]=arr[temp1][temp2];
	}
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }

	return 0;
}