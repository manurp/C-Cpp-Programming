#include <iostream>
using namespace std;

double f(double x) {return (x*x+1.0/x);}

void plot(double fcn(double),double x0,double incr,int n) {
	for (int i=0;i<n;i++) {
		cout<<"x0:"<<x0<<" f(x):"<<fcn(x0)<<endl;
		x0+=incr;
	}
}

int main() {
	cout<<"The plot function:\n";
	plot(f,0.1,0.01,10);

	return 0;
}
