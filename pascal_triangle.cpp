#include<iostream>
using namespace std;

int main()
{
	int m,n;
	cout<<"Input rows: ";
	cin>>m;
	//m=5;
	n=m*2;
	int a[m+1][n+1];
	for(int i=0;i<=n;i++)
		a[0][i]=0;
	for(int i=0;i<=m;i++)
		a[i][0]=a[i][n]=0;

	a[0][m]=a[m][0]=a[m][n]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<n;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j+1];

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(!a[i][j])
				cout<<" ";
			else
				cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;

}