#include <iostream>
using namespace std;

namespace name1{
	int v11 =1;
	int v12 = 2;
}

namespace name2 {
	int v21 = 3;
	int v22 = 4;
}

using namespace name1;
using name2::v21;

int main()
{
	cout<<v11<<endl;
	cout<<name1::v12<<endl;
	cout<<v21<<endl;
	cout<<name2::v21<<endl;
	return 0;
}