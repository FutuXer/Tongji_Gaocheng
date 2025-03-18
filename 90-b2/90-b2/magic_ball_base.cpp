/* 2353726 付煜超 信01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

int strlow(char str[])
{
	for (int i = 0; i < 3; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}

	}
	if (strcmp(str, "end\n") == 0)
		return 0;
	else
	{
		return 1;
	}
}

void checkclear(int row, int col, char dig[12][12], char color[12][12])
{
	cout << endl;
	cout << "可选择的消除提示（不同色标识）：" << endl;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			color[i][j] = 0;
		}
	}
	//初始化颜色

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			//dig[i-1][j]标记的情况
			if (dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//dig[i+1][j]标记的情况
			if (dig[i][j - 1] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}

			//dig[i][j+1]标记的情况
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}

			//dig[i][j-1]标记的情况
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j + 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}

			//上下左右全相等
			if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
				color[i - 1][j] = 1;
				color[i][j + 1] = 1;
				color[i][j - 1] = 1;
			}
				
			//00X的情况
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i + 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}
			if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//X00的情况
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}
			if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}

			//X上00的情况
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j + 1] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i + 1][j] && dig[i - 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i + 1][j] = 1;
			}

			//X下00的情况
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j - 1] = 1;
			}
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j + 1] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i][j + 1] = 1;
			}
			if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i - 1][j] && dig[i + 1][j] != dig[i][j])
			{
				color[i][j] = 1;
				color[i - 1][j] = 1;
			}
		
		}
	}

	int row0;
	char letter;
	row0 = 0;
	for (int i = 0; i <= col; i++, row0++)
	{
		if (i == 0)
			cout << "  |";
		else
			cout << std::right << setw(3) << row0;
	}
	cout << endl;
	for (int i = 0; i <= col; i++)
	{
		if (i == 0)
			cout << "--+";
		else
			cout << "---";
	}
	cout << "-" << endl;
	letter = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << letter << " |";
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cout << "  ";
				cct_setcolor(14, 2);
				cout << int(dig[i][j]);
				cct_setcolor();
			}
			else
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
		}
		cout << endl;
		letter++;
	}
	cout << endl;
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
//检查是否可以消除

int checkdig(int row, int col, char dig[12][12], char color[12][12])
{
	int xiao = 0;
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col - 2; j++)
		{
			int k = 1;
			while (1)
			{
				if (dig[i][k + j] != dig[i][j])
					break;
				else
					k++;
			}
			if (k >= 3)
			{
				for (int m = 0; m < k; m++)
				{
					color[i][m + j] = 1;
				}
				xiao = 1;
			}
		}
	}
	//确定行数需要上色的数字
	for (int i = 1; i <= col; i++)
	{
		for (int j = 1; j <= row - 2; j++)
		{
			int k = 1;
			while (1)
			{
				if (dig[j + k][i] != dig[j][i])
					break;
				else
					k++;
			}
			if (k >= 3)
			{
				for (int m = 0; m < k; m++)
				{
					color[j + m][i] = 1;
				}
				xiao = 1;
			}
		}
	}
	//确定列数数需要上色的数字
	return xiao;
}
//检查上色函数

void supplydig(int row, int col, char dig[12][12], char color[12][12], int sj)
{
	int xiao = 0;
	int row0 = 0;
	char letter = 0;
	cout << endl;
	cout << "按回车键进行新值填充..." << endl;
	cout << "新值填充后的数组（不同色标识）：" << endl;
	char back;
	while (1)
	{
		back = _getch();
		if (back == '\r')
		{
			break;
		}
		else
		{
			continue;
		}
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				dig[i][j] = 1 + rand() % (9);
			}
		}
	}
	row0 = 0;
	for (int i = 0; i <= col; i++, row0++)
	{
		if (i == 0)
			cout << "  |";
		else
			cout << std::right << setw(3) << row0;
	}
	cout << endl;
	for (int i = 0; i <= col; i++)
	{
		if (i == 0)
			cout << "--+";
		else
			cout << "---";
	}
	cout << "-" << endl;
	letter = 'A';
	for (int i = 1; i <= row; i++)
	{
		cout << letter << " |";
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cout << "  ";
				cct_setcolor(14, 3);
				cout << int(dig[i][j]);
				cct_setcolor();
			}
			else
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
		}
		cout << endl;
		letter++;
	}
	cout << endl;
	char jieshu[4] = { 0 };
	xiao = checkdig(row, col, dig, color);
	if (xiao == 0)
	{
		cout << "初始已无可消除项" << endl;
		if (sj == 2)
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
		if (sj == 3)
		{
			checkclear(row, col, dig, color);
		}
	}
	if (xiao == 1)
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				color[i][j] = 0;
			}
		}
		//初始化颜色
		cout << endl;
		cout << "初始可消除项（不同色标识）：" << endl;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[i][k + j] != dig[i][j])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[i][m + j] = 1;
					}
					xiao = 1;
				}
			}
		}
		//确定行数需要上色的数字
		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[j + k][i] != dig[j][i])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[j + m][i] = 1;
					}
					xiao = 1;
				}
			}
		}
		//确定列数数需要上色的数字
		row0 = 0;
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 1)
				{
					cout << "  ";
					cct_setcolor(14, 3);
					cout << int(dig[i][j]);
					cct_setcolor();
				}
				else
				{
					cout << std::right << setw(3) << int(dig[i][j]);
				}
			}
			cout << endl;
			letter++;
		}
		dropdig(row, col, dig, color, xiao, sj);
	}
}
//新值填充函数

void dropdig(int row, int col, char dig[12][12], char color[12][12], int x, int sj)
{
	cout << endl;
	int row0 = 0;
	char letter = 0;
	if (x == 1)
	{
		cout << "按回车键进行数组下落除0操作..." << endl;
		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		for (int j = 1; j <= col; j++)
		{
			int times = 0;
			for (int i = 1; i <= row; i++)
			{

				if (color[i][j] == 1)
				{				
					color[i][j] = 0;
					for (int k = i - 1; k > times; k--)
					{
						dig[k + 1][j] = dig[k][j];
						color[k + 1][j] = color[k][j];
					}
					times++;
					dig[times][j] = 0;
					color[times][j] = 1;				
				}
			}
		}
		row0 = 0;
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 1)
				{
					cout << "  ";
					cct_setcolor(14, 4);
					cout << int(dig[i][j]);
					cct_setcolor();
				}
				else
				{
					cout << std::right << setw(3) << int(dig[i][j]);
				}
			}
			cout << endl;
			letter++;
		}
		supplydig(row, col, dig, color, sj);
	}
	if (x == 0)
	{
		cout << "初始无可消除项，本小题无法测试，请再次运行" << endl;
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
}
//下落除0函数

void dig_ini(int row, int col, int sj)
{
	srand(static_cast<unsigned int>(time(nullptr)));


	char dig[12][12] = { 0 };
	char color[12][12] = { 0 };

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			dig[i][j] = 1 + rand() % (9);
		}
	}
	
	if (sj == 6 || sj == 7 || sj == 8 || sj == 9)
	{
		ini_struct(row,col,dig,color,sj);
	}
	int row0 = 0;
	if (sj != 6 && sj != 7 && sj != 8 && sj != 9)
	{
		cout << "初始数组:" << endl;
	
		for (int i = 0; i <= col; i++, row0++)
		{
			if (i == 0)
				cout << "  |";
			else
				cout << std::right << setw(3) << row0;
		}
		cout << endl;
		for (int i = 0; i <= col; i++)
		{
			if (i == 0)
				cout << "--+";
			else
				cout << "---";
		}
		cout << "-" << endl;
		char letter = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << letter << " |";
			for (int j = 1; j <= col; j++)
			{
				cout << std::right << setw(3) << int(dig[i][j]);
			}
			cout << endl;
			letter++;
		}
		cout << endl;
	}
	if (sj == 4 || sj == 5)
	{
		cout << "按回车键显示图形...";

		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		cout << endl;
		ini_struct(row, col, dig, color, sj);
	}	
	if (sj != 4 && sj != 5 && sj != 6 && sj != 7 && sj != 8 && sj != 9)
	{
		bool xiao = 0;
		char letter = 0;
		cout << "按回车键进行寻找初始可消除项的操作...";
		char back;
		while (1)
		{
			back = _getch();
			if (back == '\r')
			{
				break;
			}
			else
			{
				continue;
			}
		}
		cout << endl;
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[i][k + j] != dig[i][j])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[i][m + j] = 1;
					}
					xiao = 1;
				}
			}
		}
		//确定行数需要上色的数字
		for (int i = 1; i <= col; i++)
		{
			for (int j = 1; j <= row - 2; j++)
			{
				int k = 1;
				while (1)
				{
					if (dig[j + k][i] != dig[j][i])
						break;
					else
						k++;
				}
				if (k >= 3)
				{
					for (int m = 0; m < k; m++)
					{
						color[j + m][i] = 1;
					}
					xiao = 1;
				}
			}
		}
		//确定列数数需要上色的数字
		if (xiao == 1)
		{
			cout << "初始可消除项（不同色标识）：" << endl;
			row0 = 0;
			for (int i = 0; i <= col; i++, row0++)
			{
				if (i == 0)
					cout << "  |";
				else
					cout << std::right << setw(3) << row0;
			}
			cout << endl;
			for (int i = 0; i <= col; i++)
			{
				if (i == 0)
					cout << "--+";
				else
					cout << "---";
			}
			cout << "-" << endl;
			letter = 'A';
			for (int i = 1; i <= row; i++)
			{
				cout << letter << " |";
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cout << "  ";
						cct_setcolor(14, 3);
						cout << int(dig[i][j]);
						cct_setcolor();
					}
					else
					{
						cout << std::right << setw(3) << int(dig[i][j]);
					}
				}
				cout << endl;
				letter++;
			}
			if (sj == 1)
			{
				cout << endl;
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
		}
		else if (sj == 1 && xiao == 0)
		{
			cout << "初始已无可消除项" << endl;
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
		if (sj == 2)
		{
			dropdig(row, col, dig, color, xiao, sj);
		}
		if (sj == 3 && xiao == 1)
		{
			dropdig(row, col, dig, color, xiao, sj);
		}
		if (sj == 3 && xiao == 0)
		{
			cout << "初始已无可消除项" << endl;
			checkclear(row, col, dig, color);
		}
	}

}
//初始函数

