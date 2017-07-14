#include<iostream>
using namespace std;

class PrintJobs
{
	private:
	int npages_;
	static int nTraypages_;
	static int nJobs_;
	public:
	PrintJobs(int np):npages_(np)
	{
		++nJobs_;
		cout<<"Printing "<<np<<" pages"<<endl;
		nTraypages_-=np;
	}
	~PrintJobs(){--nJobs_;}
	static int getjobs(){return nJobs_;}
	static int getpages(){return nTraypages_;}
	static void loadPages(int np){nTraypages_+=np;}
};

int PrintJobs::nTraypages_=500;
int PrintJobs::nJobs_=0;

int main()
{
	cout<<"Jobs "<<PrintJobs::getjobs()<<endl;
	cout<<"Pages "<<PrintJobs::getpages()<<endl;
	PrintJobs job1(10);
	cout<<"Jobs "<<PrintJobs::getjobs()<<endl;
	cout<<"Pages "<<PrintJobs::getpages()<<endl;
    //PrintJobs job2(40);
	{
		PrintJobs job1(30),job2(40);
		cout<<"Jobs "<<PrintJobs::getjobs()<<endl;
	cout<<"Pages "<<PrintJobs::getpages()<<endl;
	PrintJobs::loadPages(100);
	}
	cout<<"Jobs "<<PrintJobs::getjobs()<<endl;
	cout<<"Pages "<<PrintJobs::getpages()<<endl;
}
