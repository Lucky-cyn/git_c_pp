// er_yi_xing.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


//二义性问题
//1.在继承时，基类之间、或基类与派生类之间发生成员同名时，将出现对成员访问的不确定性——同名二义性。
//2.当派生类从多个基类派生，而这些基类又从同一个基类派生，则在访问此共同基类中的成员时，将产生另一种不确定性——路径二义性。
//
//同名二义性
//同名隐藏规则——解决同名二义的方法
//当派生类与基类有同名成员时, 派生类中的成员将屏蔽基类中的同名成员。
//若未特别指明，则通过派生类对象使用的都是派生类中的同名成员;
//如要通过派生类对象访问基类中被屏蔽的同名成员，应使用基类名限定(::)。

//多继承同名隐藏举例  
//#include <iostream>  
//using namespace std;
//class B1//声明基类B1  
//{
//public:
//	int nV;
//	void fun() { cout << "Member of B1" << endl; }
//};
//class B2//声明基类B2  
//{
//public:
//	int nV;
//	void fun() { cout << "Member of B2" << endl; }
//};
//class D1 : public B1, public B2
//{
//public:
//	int nV;//同名数据成员  
//	void fun() { cout << "Member of D1" << endl; } //同名函数成员  
//};
//
//
//void main()
//{
//	D1 d1;
//	//用“对象名.成员名”访问子类成员。  
//	d1.nV = 2;//覆盖？？
//	d1.fun();
//	//加“作用域分辨符标识”, 可访问基类被屏蔽的成员  
//	d1.B1::nV = 2;
//	d1.B1::fun();
//	d1.B2::nV = 3;
//	d1.B2::fun();
//}

//----------------------------------------------------------------------------
//class A {
//public:
//	int a;
//	A(int aa = 1) 
//	{ a = aa; }
//	void print() {
//		cout << a << endl;
//	}
//};
//
//class B : public A {
//public:
//	int a;
//	B(int bb = 2) { a = bb; }
//
//};
//
//int main() {
//	B tp;
//	tp.print(); //输出结果为1
//	return 0;
//}
//----------------------------------------------------------------------------




//同名二义性的解决方法
//解决方法一：用类名来限定c1.A::f() 或c1.B::f()
//解决方法二：同名覆盖，再造接口在C 中再声明一个同名成员函数f()，该函数根据需要调用A::f() 或B::f()
//
//
//为了解决路径二义性问题，引入虚基类。
//–用于有共同基类的多继承场合(多层共祖)
//声明
//–以virtual修饰说明共同的直接基类
//例：class B1 : virtual public B
//作用
//–用来解决多继承时可能发生的对同一基类继承多次和多层而产生的二义性问题.
//–为最远的派生类提供唯一的基类成员，而不重复产生个副本。
//注意：
//–在第一级继承时就要将共同基类设计为虚基类。
//虚基类举例
//class B { public: int b; };
//class B1 : virtual public B { private: int b1; };
//class B2 : virtualpublic B { private: int b2; };
//class C : public B1, public B2 { private: float d; };
//在子类对象中，最远基类成分是唯一的。于是下面的访问是正确的：
//C cobj;
//cobj.b;


//使用最远基类成员原则  
#include <iostream>  
using namespace std;
class B0//声明基类B0  
{
public://外部接口  
	int nV;
	void fun() { cout << "Member of B0" << endl; }
};
class B1 : virtual public B0 //B0为虚基类，派生B1类  
{
public://新增外部接口  
	int nV1;
};
class B2 : virtual public B0 //B0为虚基类，派生B2类  
{
public://新增外部接口  
	int nV2;
};

class D1 : public B1, public B2//派生类D1声明  
{
public://新增外部接口  
	int nVd;
	void fund() { cout << "Member of D1" << endl; }
};
void main()//程序主函数  
{
	D1 d1;//声明D1类对象d1  
	d1.nV = 2;//使用最远基类成员  
	d1.fun();
}


//有虚基类时的构造函数的调用次序：
//无论虚基类与产生对象的派生类相隔多远，首先调用虚基类的构造函数；
//然后按继承次序调用直接基类的构造函数；
//如果有包含的对象，再按声明次序调用所包含对象类的构造函数；
//最后才是普通类型数据成员的初始化。

//有虚基类时的构造函数举例  
//#include <iostream>  
//using namespace std;
//class B0//声明基类B0  
//{
//public://外部接口  
//	B0(int n) { nV = n; cout << "B0's constructor called \n"; }
//	int nV;
//	void fun() { cout << "Member of B0" << endl; }
//};
//class B1 : virtual public B0
//{
//public:
//	B1(int a) : B0(a) { cout << "B1's constructor called \n"; }
//	int nV1;
//};
//class B2 : virtual public B0
//{
//public:
//	B2(int b) : B0(b) { cout << "B2's constructor called \n"; }
//	int nV2;
//};
//class D1 : public B1, public B2
//{
//public:
//	D1(int c) : B0(c), B1(c), B2(c), b1(c), b2(c) { cout << "D1's constructor called \n"; }
//	int nVd;
//	void fund() { cout << "Member of D1" << endl; }
//private:
//	B1 b1;
//	B2 b2;
//};
//void main()
//{
//	D1 d1(1);
//	d1.nV = 2;
//	d1.fun();
//}