// er_yi_xing.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//����������
//1.�ڼ̳�ʱ������֮�䡢�������������֮�䷢����Աͬ��ʱ�������ֶԳ�Ա���ʵĲ�ȷ���ԡ���ͬ�������ԡ�
//2.��������Ӷ����������������Щ�����ִ�ͬһ���������������ڷ��ʴ˹�ͬ�����еĳ�Աʱ����������һ�ֲ�ȷ���ԡ���·�������ԡ�
//
//ͬ��������
//ͬ�����ع��򡪡����ͬ������ķ���
//���������������ͬ����Աʱ, �������еĳ�Ա�����λ����е�ͬ����Ա��
//��δ�ر�ָ������ͨ�����������ʹ�õĶ����������е�ͬ����Ա;
//��Ҫͨ�������������ʻ����б����ε�ͬ����Ա��Ӧʹ�û������޶�(::)��

//��̳�ͬ�����ؾ���  
//#include <iostream>  
//using namespace std;
//class B1//��������B1  
//{
//public:
//	int nV;
//	void fun() { cout << "Member of B1" << endl; }
//};
//class B2//��������B2  
//{
//public:
//	int nV;
//	void fun() { cout << "Member of B2" << endl; }
//};
//class D1 : public B1, public B2
//{
//public:
//	int nV;//ͬ�����ݳ�Ա  
//	void fun() { cout << "Member of D1" << endl; } //ͬ��������Ա  
//};
//
//
//void main()
//{
//	D1 d1;
//	//�á�������.��Ա�������������Ա��  
//	d1.nV = 2;//���ǣ���
//	d1.fun();
//	//�ӡ�������ֱ����ʶ��, �ɷ��ʻ��౻���εĳ�Ա  
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
//	tp.print(); //������Ϊ1
//	return 0;
//}
//----------------------------------------------------------------------------




//ͬ�������ԵĽ������
//�������һ�����������޶�c1.A::f() ��c1.B::f()
//�����������ͬ�����ǣ�����ӿ���C ��������һ��ͬ����Ա����f()���ú���������Ҫ����A::f() ��B::f()
//
//
//Ϊ�˽��·�����������⣬��������ࡣ
//�C�����й�ͬ����Ķ�̳г���(��㹲��)
//����
//�C��virtual����˵����ͬ��ֱ�ӻ���
//����class B1 : virtual public B
//����
//�C���������̳�ʱ���ܷ����Ķ�ͬһ����̳ж�κͶ��������Ķ���������.
//�CΪ��Զ���������ṩΨһ�Ļ����Ա�������ظ�������������
//ע�⣺
//�C�ڵ�һ���̳�ʱ��Ҫ����ͬ�������Ϊ����ࡣ
//��������
//class B { public: int b; };
//class B1 : virtual public B { private: int b1; };
//class B2 : virtualpublic B { private: int b2; };
//class C : public B1, public B2 { private: float d; };
//����������У���Զ����ɷ���Ψһ�ġ���������ķ�������ȷ�ģ�
//C cobj;
//cobj.b;


//ʹ����Զ�����Աԭ��  
#include <iostream>  
using namespace std;
class B0//��������B0  
{
public://�ⲿ�ӿ�  
	int nV;
	void fun() { cout << "Member of B0" << endl; }
};
class B1 : virtual public B0 //B0Ϊ����࣬����B1��  
{
public://�����ⲿ�ӿ�  
	int nV1;
};
class B2 : virtual public B0 //B0Ϊ����࣬����B2��  
{
public://�����ⲿ�ӿ�  
	int nV2;
};

class D1 : public B1, public B2//������D1����  
{
public://�����ⲿ�ӿ�  
	int nVd;
	void fund() { cout << "Member of D1" << endl; }
};
void main()//����������  
{
	D1 d1;//����D1�����d1  
	d1.nV = 2;//ʹ����Զ�����Ա  
	d1.fun();
}


//�������ʱ�Ĺ��캯���ĵ��ô���
//������������������������������Զ�����ȵ��������Ĺ��캯����
//Ȼ�󰴼̳д������ֱ�ӻ���Ĺ��캯����
//����а����Ķ����ٰ������������������������Ĺ��캯����
//��������ͨ�������ݳ�Ա�ĳ�ʼ����

//�������ʱ�Ĺ��캯������  
//#include <iostream>  
//using namespace std;
//class B0//��������B0  
//{
//public://�ⲿ�ӿ�  
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