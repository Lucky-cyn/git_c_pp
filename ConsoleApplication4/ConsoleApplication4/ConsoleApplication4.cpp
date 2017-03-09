// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;

int main()
{
	const double pi{ 3.1415926 };
	for (double a{ 2.5 }; a <= 20.0; a += 2.5)
	{
		std::cout << "a=" << std::setw(12) << a
			<< "area=" << std::setw(12)
			<< pi*a*a << std::endl;
	}
}


