#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>


using namespace std;


void main()
{
	//�洢54���Ƶ�����
	int total[54];
	//�洢������ҵ���
	int player[3][17];
	//�洢��ǰʣ���Ƶ�����
	int leftNum = 54;
	//�������
	int ranNumber;
	//�������


	for (int i = 0; i<54; i++)
	{
		total[i] = i + 1; // �����������
	}
	//ѭ������
	for (int i = 0; i<17; i++) {
		//Ϊÿ���˷���
		for (int j = 0; j<3; j++) {
			//��������±�
			//ͨ��rand()�������������ÿ�����е�ʱ��������һ����ͬ��
			//��������������Ƶģ���Ϊ�˱��ڳ���ĵ���
			//��Ҫ����ÿ�β�ͬ�������������ʹ��srand(seed)�������������
			//����seed�Ĳ�ͬ�����ܹ�������ͬ�������,һ��ʹ�����·�ʽ��
			srand((unsigned)time(NULL));
			ranNumber = rand() % leftNum;
			//����
			player[j][i] = total[ranNumber];
			//�ƶ��Ѿ���������
			total[ranNumber] = total[leftNum - 1];
			//�ɷ��Ƶ���������1
			leftNum--;
		}
	}

	//ѭ�����������е���
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<17; j++) {
			cout << setw(3) << player[i][j];
		}
		cout << endl;
	}
	//����
	for (int i = 0; i<3; i++) {
		cout << setw(3) << total[i];
	}
	cout << endl;
}