#include <iostream>
using namespace std;

int data = 0;

namespace mySpc {
	int data = 1;
}

namespace open {
	int x = 30;
}

namespace open {
	int y = 40;
}

using namespace open;


int main()
{
    using namespace mySpc;
	//cout<<data<<endl;
	cout<<mySpc::data<<endl;
	cout<<x<<" "<<y<<endl;
	cout<<::data<<endl;
	return 0;
}
