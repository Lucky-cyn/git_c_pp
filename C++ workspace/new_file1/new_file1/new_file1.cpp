// new_file1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//double power(double x, int n)
//{
//	double a = 1.0;
//	if (n == 0)
//		return 0;
//	if (n > 0)
//		while (n > 0)
//		{
//			a *= x;
//			n--;
//		}
//	else
//		while (n < 0)
//		{
//			a /= x;
//			n++;
//		}
//	return a;
//}
//求x的n次方


//int Function(int n)
//{
//	if (n == 0)
//		return 1;
//	else
//		return n*Function(n - 1);
//}
//直接递归（求n的阶乘）

//int Function1(int x, int y)
//{
//	return (y == 0) ? x : Function1(y, x%y);
//}
//直接递归（求x和y的最大公约数）



int main()
{
	/*cout << power(2, 3)<<endl;*///求x的n次方
	/*cout << Function(4) << endl;*///直接递归（求n的阶乘）
	/*cout << Function1(28,32) << endl;*///直接递归（求x和y的最大公约数）
    return 0;
}

 