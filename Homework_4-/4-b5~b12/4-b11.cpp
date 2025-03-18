/* 2353726 信01 付煜超 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_letter(char start, char A)
{
	if (start == A)
	{
		cout << "A";
	}
	else
	{
		cout << start;
		print_letter(start - 1, 65);
		cout << start;
	}
}

void print_tower(int a, int ord, int length)
{
	int space = (length - (2 * (a - 65) + 1)) / 2;
	if (a == 64)
	{
		return;
	}
	if (a == 65) 
	{
		if (space != 0) 
		{
			cout << setw(space) << ' ';
		}
		cout << "A" << endl;
	}
	else
	{
		if (ord == 1)
		{
			print_tower(a - 1, ord, length);
		}
		if (space != 0)
		{
			cout << setw(space) << ' ';
		}
		print_letter(a,65);
		cout << endl;
		if (ord == 2)
		{
			print_tower(a - 1, ord, length);
		}
	}
}

char border(int a)
{
	if (a == 0)
	{
		return 32;
	}
	else
	{
		cout << "=";
		return border(a - 1);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(end_ch), 1, 2 * (int(end_ch) - 64) - 1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(end_ch), 2, 2 * (int(end_ch) - 64) - 1); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << border(2 * (int(end_ch) - 64) - 1) << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << border(2 * (int(end_ch) - 64) - 1) << endl;/* 按字母塔最大宽度输出= */
	print_tower(int(end_ch), 1, 2 * (int(end_ch) - 64) - 1);   //打印 A~结束字符的正三角 
	print_tower(int(end_ch - 1), 2, 2 * (int(end_ch) - 64) - 1);  //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
