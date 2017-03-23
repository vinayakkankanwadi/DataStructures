#include <iostream>

using namespace std;

class B
{
public:
	virtual void f1()
	//void f1()
	{
		cout<<"B::f1"<<endl;
	}
	virtual void f2()
	//void f2()
	{
		cout<<"B::f2"<<endl;
	}
};

class D1: public B
{
public:
	void f1()
	{
		cout<<"D1::f1"<<endl;
	}
};

class D2: public B
{
public:
	void f2()
	{
		cout<<"D2::f2"<<endl;
	}
};

int main()
{
	B *bptr  = new B();
	//D1 *d1ptr = new D1();
	//D2 *d2ptr = new D2();
	B *d1ptr = new D1();
	B *d2ptr = new D2();

	bptr->f1();
	bptr->f2();
	d1ptr->f1();
	d1ptr->f2();
	d2ptr->f1();
	d2ptr->f2();

	return 0;
}
