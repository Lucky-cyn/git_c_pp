// ConsoleApplication10.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class base
{
public:
	virtual void func()
	{
		std::cout << "aaaa" << std::endl;
	}
	virtual ~base()
	{
		std::cout << "aaa ~base" << std::endl;
	}

};
class child :public base
{
public:
	virtual void func()
	{
	std::cout << "bbbbb" << std::endl;
	}
	virtual ~child()
	{
		std::cout << "bbbb ~child" << std::endl;
	}
};
int main()
{
	base *p = new child;
	p->func();
	delete p;
	return 0;
}