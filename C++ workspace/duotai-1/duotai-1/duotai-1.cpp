// duotai-1.cpp : 定义控制台应用程序的入口点。
//虚函数列表的叙述

#include "stdafx.h"
#include <iostream>
using namespace std;
//假设我们有这样的一个类：

class Base
{
public:
	virtual void f() { cout << "Base::f" <<endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};
typedef void(*Fun)(void);

int main()
{
	//我们可以通过Base的实例来得到虚函数表
	Base b;

	Fun pFun = NULL;

	cout << "虚函数表地址：" << (int*)(&b) << endl;                                         //虚函数表地址：00AFF80C
	cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;                    //虚函数表 — 第一个函数地址：00358B34
    pFun = (Fun)*((int*)*(int*)(&b));	                                                   
    pFun();	                                                                                //Base::f

    return 0;
}


//虚函数（Virtual Function）是通过一张虚函数表（Virtual Table）来实现的。
//简称为V-Table。在这个表中，主是要一个类的虚函数的地址表，这张表解决了继承、覆盖的问题，保证其容真实反应实际的函数。
//这样，在有虚函数的类的实例中这个表被分配在了这个实例的内存中，所以，当我们用父类的指针来操作一个子类的时候，
//这张虚函数表就显得由为重要了，它就像一个地图一样，指明了实际所应该调用的函数。



//这里我们着重看一下这张虚函数表。C++的编译器应该是保证虚函数表的指针存在于对象实例中最前面的位置
//（这是为了保证取到虚函数表的有最高的性能——如果有多层继承或是多重继承的情况下）。 
//这意味着我们通过对象实例的地址得到这张虚函数表，然后就可以遍历其中函数指针，并调用相应的函数。


//任何妄图使用父类指针想调用子类中的未覆盖父类的成员函数的行为都会被编译器视为非法，所以，
//这样的程序根本无法编译通过。但在运行时，我们可以通过指针的方式访问虚函数表来达到违反C++语义的行为