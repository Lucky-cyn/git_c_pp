#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>


using namespace std;


void main()
{
	//存储54张牌的数组
	int total[54];
	//存储三个玩家的牌
	int player[3][17];
	//存储当前剩余牌的数量
	int leftNum = 54;
	//随机数字
	int ranNumber;
	//随机对象


	for (int i = 0; i<54; i++)
	{
		total[i] = i + 1; // 像数组添加牌
	}
	//循环发牌
	for (int i = 0; i<17; i++) {
		//为每个人发牌
		for (int j = 0; j<3; j++) {
			//生成随机下标
			//通常rand()产生的随机数在每次运行的时候都是与上一次相同的
			//这是有意这样设计的，是为了便于程序的调试
			//若要产生每次不同的随机数，可以使用srand(seed)函数进行随机化
			//随着seed的不同，就能够产生不同的随机数,一般使用如下方式：
			srand((unsigned)time(NULL));
			ranNumber = rand() % leftNum;
			//发牌
			player[j][i] = total[ranNumber];
			//移动已经发过的牌
			total[ranNumber] = total[leftNum - 1];
			//可发牌的数量减少1
			leftNum--;
		}
	}

	//循环输出玩家手中的牌
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<17; j++) {
			cout << setw(3) << player[i][j];
		}
		cout << endl;
	}
	//底牌
	for (int i = 0; i<3; i++) {
		cout << setw(3) << total[i];
	}
	cout << endl;
}