// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int m, n;          //ѭ������
	int temp;          //��ʱ����, ���ڽ�������

					   //��ʼ���о���ת��
	for (m = 0; m < 4; m++)
		for (n = m + 1; n < 4; n++)
		{
			temp = arr[m][n];
			arr[m][n] = arr[n][m];
			arr[n][m] = temp;
		}

	//���ת�ú��״̬
	for (m = 0; m < 4; m++)
	{
		for (n = 0; n < 4; n++)
		{
			cout << arr[m][n] << "      ";
		}
		cout << endl;     //ÿ���һ�к���л���
	}

	return 0;
}

