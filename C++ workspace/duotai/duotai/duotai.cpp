// duotai.cpp : 定义控制台应用程序的入口点。
//多态的学习记录
//多态与非多态的实质区别就是函数地址是早绑定还是晚绑定。

#include "stdafx.h"
//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void foo()
//	{
//		cout << "a" << endl;
//	}
//    virtual void fun()
//	{
//		cout << "b" << endl;
//	}
//};
//class B :public A
//{
//public:
//	void foo()
//	{
//		cout << "c" << endl;
//	}
//	void fun()
//	{
//		cout << "d" << endl;
//	}
//};
//
//int main()
//{
//	//p->foo()由于指针是个基类指针，指向是一个固定偏移量的函数，因此此时指向的就只能是基类的foo()函数的代码了，因此输出的结果还是1。
//	//而p->fun()指针是基类指针，指向的fun是一个虚函数，由于每个虚函数都有一个虚函数列表，此时p调用fun()并不是直接调用函数，
//	//而是通过虚函数列表找到相应的函数的地址，因此根据指向的对象不同，函数地址也将不同，这里将找到对应的子类的fun()函数的地址，
//	//因此输出的结果也会是子类的结果4。
//	A a;
//	B b;
//	A *p = &a;
//	p->foo();
//	p->fun();
//	p = &b;
//	p->foo();
//	p->fun();
//
//	B *ptr = (B *)&a;  
//	ptr->foo();  
//	ptr->fun();
//
//    return 0;
//}


//-------------------------------------------------------------------------------------------------------------
//多态性可以简单地概括为“一个接口，多种方法”，程序在运行时才决定调用的函数，它是面向对象编程领域的核心概念。多态(polymorphism)，字面意思多种形状。

//C++多态性是通过虚函数来实现的，虚函数允许子类重新定义成员函数，而子类重新定义父类的做法称为覆盖(override)，或者称为重写。
//（这里我觉得要补充，重写的话可以有两种，直接重写成员函数和重写虚函数，只有重写了虚函数的才能算作是体现了C++多态性

//如果函数的调用，在编译器编译期间就可以确定函数的调用地址，并生产代码，
//是静态的，就是说地址是早绑定的。而如果函数调用的地址不能在编译器期间确定，需要在运行时才确定，这就属于晚绑定。

//多态的目的则是为了接口重用。也就是说，不论传递过来的究竟是那个类的对象，函数都能够通过同一个接口调用到适应各自对象的实现方法

//最常见的用法就是声明基类的指针，利用该指针指向任意一个子类对象，调用相应的虚函数，可以根据指向的子类的不同而实现不同的方法


//小结：1、有virtual才可能发生多态现象  
// 2、不发生多态（无virtual）调用就按原类型调用  
#include<iostream>  
using namespace std;

class Base
{
public:
	virtual void f(float x)
	{
		cout << "Base::f(float)" << x << endl;
	}
	void g(float x)
	{
		cout << "Base::g(float)" << x << endl;
	}
	void h(float x)
	{
		cout << "Base::h(float)" << x << endl;
	}
};
class Derived : public Base
{
public:
	 void f(float x)
	{
		cout << "Derived::f(float)" << x << endl;   //多态、覆盖  
	}
	void g(int x)
	{
		cout << "Derived::g(int)" << x << endl;     //隐藏  
	}
	void h(float x)
	{
		cout << "Derived::h(float)" << x << endl;   //隐藏  
	}
};
int main(void)
{
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;
	// Good : behavior depends solely on type of the object  
	pb->f(3.14f);   // Derived::f(float) 3.14  
	pd->f(3.14f);   // Derived::f(float) 3.14  

					// Bad : behavior depends on type of the pointer  
	pb->g(3.14f);   // Base::g(float)  3.14  
	pd->g(3.14f);   // Derived::g(int) 3   

					// Bad : behavior depends on type of the pointer  
	pb->h(3.14f);   // Base::h(float) 3.14  
	pd->h(3.14f);   // Derived::h(float) 3.14  
	return 0;
}









