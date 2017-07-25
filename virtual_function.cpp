#include <iostream>
using namespace std;
#include <cstring>

class Person {
protected:
	string name_;
	int age_;
public:
	// Person(string n,int age):name_(n),age_(age){}
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};

class Professor: public Person {
	// string n;
	// int age;
	int publications;
	static int cur_id;
	int obj_cur_id;
public:
	Professor() {
		cur_id++;
		obj_cur_id = cur_id;
	}
	virtual void getdata() {
		cin>>name_>>age_>>publications;
	}

	virtual void putdata() {
		cout<<name_<<" "<<age_<<" "<<publications<<" "<<obj_cur_id<<endl;
	}
};

class Student : public Person {
	int marks[6];
	static int cur_id ;
	int obj_cur_id;
	int sum=0;
public:
	Student() {
		cur_id++;
		obj_cur_id = cur_id;
	}
	virtual void getdata() {
		cin>>name_>>age_;
		
		for (int i=0;i<6;i++){
			cin>>marks[i];
			sum+=marks[i];
		}
	}
	virtual void putdata() {
		cout<<name_<<" "<<age_<<" "<<sum<<" "<<obj_cur_id<<endl;
	}
};

int Professor::cur_id = 0;
int Student::cur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
