// ConsoleApplication9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "��ͷ.h"
#include <iostream>
using namespace std;

Circle::Circle()
{
	this->r = 5.0;
}

Circle::Circle(double R)
{
	this->r = R;
}

double Circle::Area()
{
	return 3.14*r*r;
}
int main()
{
	Circle c(3);
	cout << "Area=" << c.Area() << endl;
	return 1;
}