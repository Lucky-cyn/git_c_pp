// ConsoleApplication8.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"

using namespace std;

template<class T>void publicfunction(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
int main() 
{
	int n1 = 100, n2 = 200;
	publicfunction(&n1,&n2);
	std::cout << n1 << "," << n2 <<std::endl;
}
