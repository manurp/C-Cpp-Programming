#include <iostream>
using namespace std;
// All commented out functions have inaccessible data members
class A
{
private:int x;
protected:int y;
public:	int z;
};

class B :public A
{
	private:int u;
	protected:int v;
public:int w;
// f(){x;}
};

class C:protected A
{
	private:int u;
	protected:int v;
	public:int w;
	// f(){x;}
};

class D : private A
{
private:int u;
protected:int v;
public:int w;
// f(){x;}
};

class E : public B
{
	public:/*f(){x;u;}*/
};

class F :public C
{
	public:/*f(){x;u;}*/
};

class G : public D
{
	public:/*f(){x;y;z;u;}*/
};

f(A&a,B&b,C&c,D&d,E&e,F&f,G&g)
{
	a.z;

	b.w;
	b.z;

	c.w;

	d.w;

	e.w;
	e.z;

	f.w;

	g.w;
}


int main()
{
    return 0;
}








