#include<iostream>
using namespace std;
class Matrix;
class Vector
{
	private:
	int e_[3];
	int n_;
	public:
	Vector(int n):n_(n)
	{
		for(int i=0;i<n;++i)
			e_[i]=i+1;
	}
	~Vector(){cout<<"vector dtor\n";}
	void show()
	{
		for(int i=0;i<n_;++i)
			cout<<e_[i]<<" ";
		cout<<endl<<endl;
	}
	void clear()
	{
		for(int i=0;i<n_;i++)
			e_[i]=0;
	}
	friend Vector Prod(Matrix* pM,Vector* pV);
};

class Matrix
{
	private:
	int e_[3][3];
	int m_,n_;
	public:
	Matrix(int m,int n):m_(m),n_(n)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				e_[i][j]=i+j;
	}
	~Matrix(){cout<<"Matrix dtor\n";}
	void show()
	{
		for(int i=0;i<m_;i++)
		{for(int j=0;j<n_;j++)
				cout<<e_[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	friend Vector Prod(Matrix* pM,Vector* pV);
};

Vector Prod(Matrix* pM,Vector* pV)
{
	Vector v(pM->m_);v.clear();
	for(int i=0;i<pM->m_;i++)
		for(int j=0;j<pM->n_;j++)
			v.e_[i]+=pM->e_[i][j]*pV->e_[j];
			return v;
}

int main()
{
	Matrix m(2,3);
	Vector v(3);
	Vector vv=Prod(&m,&v);
	m.show();
	v.show();
	vv.show();
	return 0;
}
