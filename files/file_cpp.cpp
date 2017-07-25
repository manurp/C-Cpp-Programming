#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fileobj("file.txt");
	if(fileobj.is_open()) {
		fileobj << "The first file created using fstream in c++\n"<<endl;
	} 
	else {
		cout << "File is not open!";
	}
	fileobj.close();
}