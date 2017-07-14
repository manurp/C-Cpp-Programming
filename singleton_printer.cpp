#include<iostream>
using namespace std;

class Printer
{
	bool blackNwhite;
	bool bothSided;

	Printer(bool bw=false,bool bs=false):blackNwhite(bw),bothSided(bs){cout<<"Printer constructed\n";}

	static Printer *myprinter;
	public:
	~Printer(){cout<<"Printer destructed\n";}

	static const Printer& printer(bool bw=false,bool bs=false)
	{
		if(!myprinter)
		{
			myprinter=new Printer(bw,bs);
		}
		return *myprinter;
	}
	void print(int np)const{cout<<"Printing "<<np<<" pages"<<endl;}
};

Printer *Printer::myprinter=0;
int main()
{
   // Printer::printer(true);
	Printer::printer().print(10);
	Printer::printer().print(20);
	Printer::printer().~Printer();
	return 0;
}
