//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int c[1505][1505];
int l,s;
bool solve(int mid)
{
	for(int i = mid;i <= l;i++)
    {
            for(int j = mid;j <= l;j++)
            {
                int tmp = c[i][j] - c[i-mid][j-mid];
                if(tmp <= s) return true;
            }
     }
        return false;
}
int main()
{
	int t;  cin>>t;
	while(t--)
	{
		cin>>s;
		string a,b;  cin>>a>>b;
		  l = a.length();
		  for(int i=0;i<l;++i)
		  {
		  	  for(int j=0;j<l;++j)
		  	  {
		  	  	if(a[i]==b[j]){
                   // cout<<i<<" "<<j<<" "<<c[i][j]<<"\n ";
		  	  	 c[i+1][j+1] = c[i][j] ;}
		  	  	 else{
                 //cout<<"else: "<<i<<" "<<j<<" "<<c[i][j]<<"\n ";
		  	  	 c[i+1][j+1] = c[i][j] +1;
		  	  	 }
			  }
		  }
		  int low = 0,high = l,mid;
            while(low < high)
			{
                //mid = (low + high + 1) >> 1;
                mid = (low+high+1)/2;
                if(solve(mid)) low = mid;
                else high = mid - 1;
            }
		  cout<<low<<endl;
	}
}
