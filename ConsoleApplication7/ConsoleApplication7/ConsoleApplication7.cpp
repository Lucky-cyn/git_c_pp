// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void Upset(int a[], int n)
{
	int index, tmp, i;
	srand((unsigned)time(NULL));

	for (i = n - 1; i>0; i--)
	{
		index = 1 + rand() % i;//产生一定范围随机数的通用表示公式 :a + rand() % n.....a是起始值，n是整数的范围
		tmp = a[i];
		a[i] = a[index];//把一个随机数赋给第53个元素
		a[index] = tmp;
	}
}

//冒泡排序
int* BubbleSort(int* ary, int length)
{
	int i, j, tmp;
	for (i = 0; i<length - 1; i++)
	{
		tmp = ary[i];

		for (j = length - 1; j>i; j--)
		{
			
			if (tmp > ary[j])
			{
				ary[i] = ary[j];
				ary[j] = tmp;
				tmp = ary[i];
			}
		}
	}

	return ary;
}


int main()
{
	int pArr[60];
	for (int i{ 0 }; i <= 53; i += 1)
	{
		pArr[i] = i + 1;
	}
	Upset(pArr, 54);
	for (int j{ 0 }; j <= 53; j += 1)
	{
		cout << pArr[j] << endl;
	}
	int pla1[25];
	int pla2[25];
	int pla3[25];
	
	cout << "pla1:" << " ";
	for (int h = 0; h< 54; h+=3)
	{
		cout << pArr[h] << " ";
		
	}
	cout << endl;

	cout << "pla1:" << " ";
	for (int h = 0; h< 54; h += 3)
	{
		cout << pArr[h+1] << " ";

	}
	cout << endl;

	cout << "pla1:" << " ";
	for (int h = 0; h< 54; h += 3)
	{
		cout << pArr[h+2] << " ";

	}
	
}




//#include "stdafx.h"
//#include <iostream>
//#include <time.h>
//#include <vector>
//using namespace std;
//
//void upset(int a[], int n)
//{
//	int index, tmp, i;
//	srand((unsigned)time(NULL));
//
//	for (i = n - 1; i>0; i--)
//	{
//		index = 1 + rand() % i;//产生一定范围随机数的通用表示公式 :a + rand() % n.....a是起始值，n是整数的范围
//		tmp = a[i];
//		a[i] = a[index];//把一个随机数赋给第53个元素
//		a[index] = tmp;
//	}
//}
//
//void print(int* pdata, int count) {
//	for (int i = 0; i< count; i++) {
//		cout << pdata[i] << " ";
//	}
//	cout << endl;
//}
//
//
//int* bubblesort(int* ary, int length)
//{
//	int i, j, tmp;
//	for (i = 0; i<length - 1; i++)
//	{
//		tmp = ary[i];
//
//		for (j = length - 1; j>i; j--)
//		{
//			//找到数组中最小的数，并交换
//			if (tmp > ary[j])
//			{
//				ary[i] = ary[j];
//				ary[j] = tmp;
//				tmp = ary[i];
//			}
//		}
//	}
//
//	return ary;
//}
//
//
//
//int main()
//{
//	int parr[60];
//	for (int i{ 0 }; i <= 54; i += 1)
//	{
//		parr[i] = i + 1;
//	}
//	upset(parr, 54);
//	for (int j{ 0 }; j <= 53; j += 1)
//	{
//		cout << parr[j] << endl;
//	}
//	int pla1[20];
//	int pla2[20];
//	int pla3[20];
//
//	for (int f{ 0 }; f <= 18; f += 1)
//	{
//		pla1[f] = parr[f];
//		pla2[f] = parr[f + 18];
//		pla3[f] = parr[f + 36];
//
//	}
//
//	bubblesort(pla1, 18);
//	cout << "pla1:";
//	print(pla1, 18);
//
//
//
//
//	cout << endl;
//	bubblesort(pla2, 18);
//	cout << "pla2:";
//	print(pla2, 18);
//
//
//
//	cout << endl;
//	bubblesort(pla3, 18);
//	cout << "pla3:";
//	print(pla3, 18);
//	cout << endl;
//
//	return 0;
//}