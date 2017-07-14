#include <iostream>
#include <string>
#include<iterator>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
    int n;
  string name;
  string n1;
  vector<string> v;
  //vector<string> v1;
  cin>>n;//>>p;
  //cout<<n<<endl;
for(int i=0;i<n+1;i++){
    getline(cin,name);
    v.push_back(name);
}
//cout<<p<<endl;
/*for(int i=0;i<p;i++){
    getline(cin,n1);
    v1.push_back(n1);
}*/
  //cout << "Please, enter your full name: ";
string s;
int found=v[1].find(' ');
cout<<found<<" ";
int f=v[1].find(' ',found+1);cout<<f<<"\n";
s=v[1].substr(found+1,f-found);
cout<<s;
cout<<endl;
//vector<string>::const_iterator pos;
// pos = find(v.begin(), v.end(),"tag1"); - v.begin();
auto it = find(v.begin(), v.end(), "tag1");
auto index = distance(v.begin(), it);
cout<<index<<endl;
//cout<<pos<<"\n";
  for (int i=1;i<=n;i++)
  cout<<v[i]<<endl;
  /*for (int i=0;i<p;i++)
  cout<<v1[i]<<endl;
*/
  //cout << "Hello, " << name << "!\n";

  return 0;
}
