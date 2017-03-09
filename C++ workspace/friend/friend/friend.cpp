// friend.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cmath>
using namespace std;


class A
{
private:
	int* n;

public:
	A()
	{
		n = new int[10];
		n[0] = 1;
		cout << "constructor is called\n";
	}

	A(const A& a)
	{
		n = new int[10];
		memcpy(n, a.n, 10);
		cout << "copy constructor is called\n";
	}

	~A()
	{
		cout << "destructor is called\n";
		delete n;
	}

	void get()
	{
		cout << "n[0]: " << n[0] << endl;
	}
};


int main()
{
	A* a = new A();
	A b = *a;
	delete a;

	b.get();

	return 0;
}
