// ConsoleApplication5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

void output(int* arr, int count)
{
	for (int i{ 0 }; i < count; i += 1)
	{
		cout << arr[i] << "" << endl;
	}
}
void Sort(int* arr, int count) 
{
	int a;
	for (int i{ 0 }; i < count; i += 1)
	{
		for (int j{ count - 1 }; j >= i; j -= 1)
		{
			if (arr[j] < arr[j - 1])
			{
				a = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = a;
			}
		}
		cout << "第" << i << "次" << endl;
		output(arr,count);
	}
}


int main()
{
	int * pcount = new int;
	cout << "请输入数组长度：" << endl;
	cin >> *pcount;
	cout << "请输入数组元素:" << endl;
	int* pArray = new int[*pcount];
	for (int p{ 0 }; p < *pcount; p += 1)
	{
		cin >> pArray[p];
	}
	Sort(pArray, *pcount);
	cout << "最终结果为:" << endl;
	output(pArray, *pcount);

	
	delete pcount;
	delete []pArray;
	return 0;
}

