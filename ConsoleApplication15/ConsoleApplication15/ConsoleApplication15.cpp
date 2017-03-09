// ConsoleApplication15.cpp : 定义控制台应用程序的入口点。
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
		str = new char[strlen(p) + 1];//申请资源，strlen：字符串长度
		strcpy(str, p);//从p地址开始复制到str地址开始的字符串中
	}
	~String()//析构函数
	{
		delete[]str;
		str = NULL;
	}
	int length() { return strlen(str); }//取str字符串长度
	char &char_at(int i)
	{
		if (i < 0 || i >= strlen(str))
		{
			cerr << "超出字符串范围!\n";
			exit(-1);
		}//验证字符串溢出
		return str[i];
	}
	const char *get_str() { return str; }//返回字符串指针
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

