// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "标头.h"
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