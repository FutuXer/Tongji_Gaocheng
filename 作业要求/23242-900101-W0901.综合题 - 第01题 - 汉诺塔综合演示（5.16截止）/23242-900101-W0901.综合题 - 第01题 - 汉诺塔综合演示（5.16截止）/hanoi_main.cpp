/* 信01 2353726 付煜超 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
extern int step;
extern int a0;
extern int b0;
extern int c0;                                 //记录圆盘个数// 
extern int A[10];
extern int B[10];
extern int C[10];     //三个柱子//
extern int t;                               //延时
extern int display;                           //显示数值


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	while (true)
	{
		step = 1;
		b0 = 0;
		c0 = 0;                                   //记录圆盘个数// 
		for (int i = 0; i < 10; i++)
			A[i] = 0;
		for (int i = 0; i < 10; i++)
			B[i] = 0;
		for (int i = 0; i < 10; i++)
			C[i] = 0;
		t = 0;                                   //延时
		display = 0;                             //显示数值
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 40, 120, 9000);

		int menudig;
		menudig = menu();
		cout << endl;
		cout << endl;
		cout << endl;
		if (menudig == 48)
		{
			break;
		}
		if (menudig == 49)
			hanoi_s1(1);
		if (menudig == 50)
			hanoi_s2(2);
		if (menudig == 51)
			hanoi_s348(3);
		if (menudig == 52)
			hanoi_s348(4);
		if (menudig == 53)
			hanoi_s56789(5);
		if (menudig == 54)
			hanoi_s56789(6);
		if (menudig == 55)
			hanoi_s56789(7);
		if (menudig == 56)
			hanoi_s56789(8);
		if (menudig == 57)
			hanoi_s56789(9);
		cout << "游戏结束，按回车键返回菜单." << endl;
		char ch = _getch();

		while (ch != 13)
		{
			ch = _getch();
			continue;
		}
		cct_cls();
	}


	return 0;
}
