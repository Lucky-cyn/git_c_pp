// ConsoleApplication15.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class String
{
	char *str;
public:
	String()
	{
		str = NULL;
	}
	String(const char *p)
	{
		str = new char[strlen(p) + 1];//������Դ��strlen���ַ�������
		strcpy(str, p);//��p��ַ��ʼ���Ƶ�str��ַ��ʼ���ַ�����
	}
	~String()//��������
	{
		delete[]str;
		str = NULL;
	}
	int length() { return strlen(str); }//ȡstr�ַ�������
	char &char_at(int i)
	{
		if (i < 0 || i >= strlen(str))
		{
			cerr << "�����ַ�����Χ!\n";
			exit(-1);
		}//��֤�ַ������
		return str[i];
	}
	const char *get_str() { return str; }//�����ַ���ָ��
	String &copy(const char *p)
	{
		delete[]str;
		str = new char[strlen(p) + 1];
		strcpy(str, p);
		return *this;
	}
	String &copy(const char *p)
	{
		return copy(s.str);
	}

};

int main()
{
	String s1;
	s1.copy("xyz");
	cout << s1.get_str << endl;
    return 0;
}

