/* 2353726 付煜超 信01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void jieshu()
{
	cout << "本小题结束，请输入End继续...";
	int x = 0, y = 0;
	cct_getxy(x, y);
	cin.clear();
	cin.ignore(1024, '\n');
	while (1)
	{
		char jieshu[2048] = { 0 };
		for (int i = 0; ; i++)
		{
			jieshu[i] = getchar();
			if (jieshu[i] == '\n')
			{
				break;
			}
		}
		if (strlow(jieshu) == 0)
		{
			cct_cls();
			break;
		}
		else
		{
			cct_gotoxy(x, y);
			for (int i = 0; i < 3; i++)
			{
				jieshu[i] = 0;
			}
			cct_gotoxy(x, y);
			cout << "   " << endl;
			cout << "输入错误，请重新输入";
			cct_gotoxy(x, y);
			continue;
		}
	}
}
