#include <iostream>
#include <cstring>
using namespace std;

class St {
public:
	typedef enum GENDER{male=0,female};
	St(char* n,GENDER g):name(strcpy(new char[strlen(n)+1],n)),gender(g){}
	void setRoll(int r){roll=r;}
	GENDER getGender(){return gender;}
	friend ostream& operator<<(ostream& os,const St& s)
	{
		cout<<((s.gender==St::male)?"Male ":"Female ")<<s.name<<" "<<s.roll<<endl;
		return os;
	}
private:
	char *name;GENDER gender;
	int roll;
};

class StReg {
	St **rec;       //List of students
	int nStudents;
public:
	StReg(int size):rec(new St*[size]),nStudents(0){}
	void add(St* s){rec[nStudents]=s;
		s->setRoll(++nStudents);}
	St* getStudent(int r){return(r==nStudents+1)?0:rec[r-1];}
};

extern StReg *reg;

namespace App1 {
    //extern StReg *reg;
	void ProcessStudents() {
		cout<<"MALE STUDENTS: "<<endl;
		int r=1;St* s;
		while(s = reg->getStudent(r++))
			if(s->getGender() == St::male)
				cout<<*s;
			cout<<"\n\n";
			return;
	}
}

namespace App2 {
    //extern StReg *reg;
	void ProcessStudents() {
		cout<<"FEMALE STUDENTS: "<<endl;
		int r=1;St* s;
		while(s = reg->getStudent(r++))
			if(s->getGender()==St::female)
				cout<<*s;
			cout<<"\n\n";
			return;
	}
}

StReg *reg = new StReg(1000);

int main()
{
	St s1("Manoj",St::male); reg->add(&s1);
	St s2("Bhoomi",St::female);reg->add(&s2);

	App1::ProcessStudents();
	App2::ProcessStudents();

	return 0;
}
