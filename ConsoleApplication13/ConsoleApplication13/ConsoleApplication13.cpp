// ConsoleApplication13.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	char a, b, c, d=0;
	cout << "����4λ��" << endl;
	cin >> n;
	a = n / 1000;
	n = n % 1000;
	b = n / 100;
	n = n % 100;
	c = n / 10;
	n = n % 10;
	b = n;
	m = ((d * 10 + c) * 10 + b) * 10 + a;
	cout << m << endl;
    return 0;
}

