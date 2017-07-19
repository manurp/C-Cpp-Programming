#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception{};
class Myclass{};

void h() {
	Myclass a;
	//throw 1;
	 //throw 2.5;
	//throw MyException();
	// throw exception();
	// throw Myclass();
}

void g() {
	Myclass a;
	try {
		h();
	}
	catch(int) {cout<<"int\n";}
	catch(double) {cout<<"double\n";}
	catch(...) {throw;} //Withot this line the default is also throwing that exception 
}

void f() {
	Myclass a;
	try {
		g();
	}
	catch(MyException) {cout<<"MyException\n";}
	catch(exception){ cout<<"exception\n";}
	catch(...) {throw;}
}

int main() {
	try {
		f();
	}
	catch(...) {cout<<"Unknown\n";}

	return 0;
}
