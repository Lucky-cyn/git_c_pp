// ConsoleApplication5.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "��" << i << "��" << endl;
		output(arr,count);
	}
}


int main()
{
	int * pcount = new int;
	cout << "���������鳤�ȣ�" << endl;
	cin >> *pcount;
	cout << "����������Ԫ��:" << endl;
	int* pArray = new int[*pcount];
	for (int p{ 0 }; p < *pcount; p += 1)
	{
		cin >> pArray[p];
	}
	Sort(pArray, *pcount);
	cout << "���ս��Ϊ:" << endl;
	output(pArray, *pcount);

	
	delete pcount;
	delete []pArray;
	return 0;
}

