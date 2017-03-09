// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	int arr[4][4] = { { 1,  2,  3,   4 },
	{ 5,  6,  7,   8 },
	{ 9,  10, 11, 12 },
	{ 13, 14, 15, 16 } };
	int m, n;          //循环控制
	int temp;          //临时变量, 用于交换数据

					   //开始进行矩阵转置
	for (m = 0; m < 4; m++)
		for (n = m + 1; n < 4; n++)
		{
			temp = arr[m][n];
			arr[m][n] = arr[n][m];
			arr[n][m] = temp;
		}

	//输出转置后的状态
	for (m = 0; m < 4; m++)
	{
		for (n = 0; n < 4; n++)
		{
			cout << arr[m][n] << "      ";
		}
		cout << endl;     //每输出一行后进行换行
	}

	return 0;
}

