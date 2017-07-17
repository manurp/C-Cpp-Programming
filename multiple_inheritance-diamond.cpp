#include <iostream>
using namespace std;

class Person {
	int x;
public:
	Person(int x):x(x){cout<<"Person\n";}
	Person(){}
	virtual void teach() = 0;
};

class Teacher : virtual public Person {
	// int x;
public:
	Teacher(int x):Person(x){cout<<"Teacher\n";}
	virtual void teach() {
		cout<<"Teacher teaches\n";
	}
};

class Student: public virtual Person
{
public:
	Student(int x):Person(x){cout<<"Student\n";}
	virtual void teach() {
		cout<<"Student teaches\n";
	}
};

class TA : public Teacher, public Student
{
public:
	TA(int x):Student(x),Teacher(x){cout<<"TA\n";}
	void teach() {
		cout<<"TA teaches\n";
	}
};

int main(int argc, char const *argv[])
{
    Student s(10);
    Person* p;
    p = &s;
    p->teach();
    cout<<endl;

	TA t(30);
	p = &t;
	p->teach();
	return 0;
}
