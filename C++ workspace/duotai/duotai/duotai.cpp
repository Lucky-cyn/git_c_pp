// duotai.cpp : �������̨Ӧ�ó������ڵ㡣
//��̬��ѧϰ��¼
//��̬��Ƕ�̬��ʵ��������Ǻ�����ַ����󶨻�����󶨡�

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
//	//p->foo()����ָ���Ǹ�����ָ�룬ָ����һ���̶�ƫ�����ĺ�������˴�ʱָ��ľ�ֻ���ǻ����foo()�����Ĵ����ˣ��������Ľ������1��
//	//��p->fun()ָ���ǻ���ָ�룬ָ���fun��һ���麯��������ÿ���麯������һ���麯���б���ʱp����fun()������ֱ�ӵ��ú�����
//	//����ͨ���麯���б��ҵ���Ӧ�ĺ����ĵ�ַ����˸���ָ��Ķ���ͬ��������ַҲ����ͬ�����ｫ�ҵ���Ӧ�������fun()�����ĵ�ַ��
//	//�������Ľ��Ҳ��������Ľ��4��
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
//��̬�Կ��Լ򵥵ظ���Ϊ��һ���ӿڣ����ַ�����������������ʱ�ž������õĺ����������������������ĺ��ĸ����̬(polymorphism)��������˼������״��

//C++��̬����ͨ���麯����ʵ�ֵģ��麯�������������¶����Ա���������������¶��常���������Ϊ����(override)�����߳�Ϊ��д��
//�������Ҿ���Ҫ���䣬��д�Ļ����������֣�ֱ����д��Ա��������д�麯����ֻ����д���麯���Ĳ���������������C++��̬��

//��������ĵ��ã��ڱ����������ڼ�Ϳ���ȷ�������ĵ��õ�ַ�����������룬
//�Ǿ�̬�ģ�����˵��ַ����󶨵ġ�������������õĵ�ַ�����ڱ������ڼ�ȷ������Ҫ������ʱ��ȷ�������������󶨡�

//��̬��Ŀ������Ϊ�˽ӿ����á�Ҳ����˵�����۴��ݹ����ľ������Ǹ���Ķ��󣬺������ܹ�ͨ��ͬһ���ӿڵ��õ���Ӧ���Զ����ʵ�ַ���

//������÷��������������ָ�룬���ø�ָ��ָ������һ��������󣬵�����Ӧ���麯�������Ը���ָ�������Ĳ�ͬ��ʵ�ֲ�ͬ�ķ���


//С�᣺1����virtual�ſ��ܷ�����̬����  
// 2����������̬����virtual�����þͰ�ԭ���͵���  
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
		cout << "Derived::f(float)" << x << endl;   //��̬������  
	}
	void g(int x)
	{
		cout << "Derived::g(int)" << x << endl;     //����  
	}
	void h(float x)
	{
		cout << "Derived::h(float)" << x << endl;   //����  
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









