#include <iostream>
#include <string>
using namespace std;

class Engineer {
protected:
	string name_;
public:
	Engineer(const string& name):name_(name){}
	virtual void processSalary() {cout<<name_<<": Process salary of Engineer\n";}
};

class Manager: public Engineer {
	Engineer* reports_[10];;
public:
	Manager(const string& name):Engineer(name){}
	void processSalary() {cout<<name_<<": Process salary for Manager\n";}
};

class Director: public Manager {
	Manager* reports_[10];
public:
	Director(const string& name):Manager(name){}
	void processSalary() {cout<<name_<<": Process salary for Director\n";}
};

int main() {
	Engineer e1("Manoj"),e2("Sathya"),e3("Shwetha");
	Manager m1("Janardhan"),m2("Bhoomika");
	Director d("Shanmuka");

	Engineer* staffs[] = {&e1, &e2, &e3, &m1, &m2, &d};

	for(int i = 0;i<sizeof(staffs)/sizeof(Engineer*);++i) staffs[i]->processSalary();
}
