#include <iostream>
#include <cstring>
using namespace std;

template<class T1=int,class T2=string>
class student {
	T1 roll_; T2 name_;
public:
	student(T1 r, T2 n):roll_(r),name_(n){}
	void print() const{cout<<"Version 1: ("<<name_<<", "<<roll_<<" )\n";}
};

template <class T1>
class student<T1,char*> {
	T1 roll_; char* name_;
public:
	student(T1 r, char* n):roll_(r),name_(strcpy(new char[strlen(n)+1],n)){}
	void print() const{cout<<"Version 2: ("<<name_<<", "<<roll_<<" )\n";}
};

int main() {
	student<int,string> s1(57,"Manoj");
	student<int> s2(24,"Bhoomi");
	student<> s3(36,"Ravi");
	student<int,char*> s4(45,"Shamantha");
	student<string> s5("JC15","Rohit");
	student<string,char*> s6("CV12","Lekhan");

	s1.print();s2.print();s3.print();s4.print();s5.print();s6.print();

	return 0;
}
