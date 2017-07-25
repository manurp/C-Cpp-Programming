#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fileobj("file.txt");
	/* Can be done in the following way
	ofstream fileobj;
	fileobj.open("simefilename");
	fileobj<<"some txt";
	fileobj.close();
	*/
	if(fileobj.is_open()) {
		fileobj << "The first file created using fstream in c++\n"<<endl;
	} 
	else {
		cout << "File is not open!";
	}
	fileobj.close();
}