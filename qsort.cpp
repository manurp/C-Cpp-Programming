#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int i,int j){
	return(i>j);
}

int main(){
	int data[]={32,74,12,35,48};

	sort(data,data+5,compare);

	for(int i=0;i<5;i++){
		cout<<data[i]<<" ";
	}
	return 0;
}