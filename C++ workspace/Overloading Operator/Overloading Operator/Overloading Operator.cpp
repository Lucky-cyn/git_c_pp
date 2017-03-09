 overloading operator.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


class intarray
{
public :
	int &operator[](int);
	const int & operator[](int)const;
	intarray(int s);
	int get_size()const { return size;}
private:
	int size;
	int *a;
};
int & intarray::operator[](int i)
{
	if (i < 0 || i >= size)
	{
		throw string("aaaa");
		return a[i];
	}
}
const int & intarray::operator[](int i)const
{
	if (i < 0 || i >= size)
	{
		throw string("aaaa");
		return a[i];
	}
}
intarray::intarray(int s)
{
	try
	{
		a = new int[s];
	}
	catch (bad_alloc)
	{
		cerr << "bbbbbbbbbbbbb\n";
		throw;
	}
	size = s;
}

int main()
{
	intarray b(5);
	int i;
	try {
		for (i = 0; i < b.get_size(); i++)
			b[i] = 2 * 1;
		for (i = 0; i < 6; i++)
			cout << b[i] << endl;
	}
	catch (string  s)
	{
		cerr << s << endl;
		cerr << "i="<<i << endl;
	}
    return 0;
}

