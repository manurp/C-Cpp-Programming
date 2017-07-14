#include <iostream>
#include <string>
using namespace std;

class Employee { //Abstract Base Class (ABC)
protected:
	string name_;
public:
	virtual void processSalary() = 0;
};

class Engineer : public Employee{
public:
	Engineer(const string& name){name_=name;}
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

class SalesExecutive : public Employee{
public:
	SalesExecutive(const string& name){name_ = name;}
	void processSalary() {cout<<name_<<": Process salary for SalesExecutive\n";}
};

int main() {
	Engineer e1("Manoj"),e2("Sathya"),e3("Shwetha");
	Manager m1("Janardhan"),m2("Bhoomika");
	SalesExecutive s1("Ravi"),s2("Shamantha");
	Director d("Shanmuka");

	Employee* staffs[] = {&e1, &e2, &e3, &s1, &s2, &m1, &m2, &d};

	for(int i = 0;i<sizeof(staffs)/sizeof(Employee*);++i) staffs[i]->processSalary();
}
