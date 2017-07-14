#include <iostream>
#include <string>
using namespace std;

typedef enum E_TYPE {Er, Mgr,Dir}E_TYPE;

class Engineer {
protected:
	string name_; E_TYPE type_;
public:
	Engineer(const string& name,E_TYPE type=Er):name_(name),type_(type){}
	E_TYPE getType() {return type_;}
	void processSalary() {cout<<name_<<": Process salary for engineer\n";}
};

class Manager: public Engineer {
	Engineer* reports_[10];
public:
	Manager(const string& name,E_TYPE type=Mgr):Engineer(name,type){}
	void processSalary() {cout<<name_<<": Process salary for Manager\n";}
};

class Director:public Manager {
	Manager* reports_[10];
public:
	Director(const string& name):Manager(name,Dir){}
	void processSalary() {cout<<name_<<": Process salary for Director\n";}
};

int main()
{
	Engineer e1("Manoj"),e2("Bhoomi");
	Manager m1("Shamantha"),m2("Ravi");
	Director d("Rohit");

	Engineer* staff[] = {&e1, &e2, &m1, &m2, &d};

	for (int i=0;i<sizeof(staff)/sizeof(Engineer*);++i) {
		E_TYPE e = staff[i]->getType();
		if(e==Er) staff[i]->processSalary();
		else if(e==Mgr) ((Manager*)staff[i])->processSalary();
		else if(e==Dir) ((Director*)staff[i])->processSalary();
		else cout<<"Invalid type\n";
	}
}
