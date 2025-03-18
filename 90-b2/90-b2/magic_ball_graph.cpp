/* 2353726 付煜超 信01 */
#include <iostream>
#include <conio.h>
#include <iomanip>	
#include <ctime>
#include <cstring>
#include <cmath>
#include "cmd_console_tools.h"
#include "magic_ball.h"
using namespace std;

void graph_check_clear(int row, int col, char dig[12][12], char color[12][12], int piccolor[12][12])
{
	char str[5] = { "◎" };
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
	//检查是否可以消除

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (color[i][j] == 1)
			{
				cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
			}
		}
	}
}

void draw_struc(int row, int col, char dig[12][12], char color[12][12], int piccolor[12][12], int sj = 0)
{
	char str1[5] = { "╔" };
	char str2[5] = { "╗" };
	char str3[5] = { "╚" };
	char str4[5] = { "╝" };
	char str5[5] = { "═" };
	char str6[5] = { "║" };
	char str7[5] = { "〇" };
	char str8[5] = { "●" };
	char str9[5] = { "╦" };
	char str10[5] = { "╠" };
	char str11[5] = { "╬" };
	char str12[5] = { "╣" };
	char str13[5] = { "╩" };
	char str14[5] = { "  " };
	char str15[5] = { "¤" };
	char str16[5] = { "◎" };
	if (sj == 4)
	{
		cct_setconsoleborder(40, row + 6, 100, 100);
		cout << "屏幕：" << row + 6 << "行40列" << endl;
		cct_showstr(1, 1, str1, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, 1, str2, 7, 0, 1, 2);
		cct_showstr(1, row + 2, str3, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, row + 2, str4, 7, 0, 1, 2);
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, 1, str5, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, row + 2, str5, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(1, i - 1, str6, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(2 * col + 3, i - 1, str6, 7, 0, 1, 2);
			Sleep(30);
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{

				cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
				Sleep(30);
			}
		}
		cct_setcolor();
	}
	if (sj == 5)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "屏幕：" << 2 * row + 5 << "行40列" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
					Sleep(10);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
					Sleep(10);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
					Sleep(10);
				}
				//第一层
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					Sleep(10);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
					Sleep(10);
				}
				//偶数层

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
						Sleep(10);

					}					
				}
				//奇数层

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						Sleep(10);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
						Sleep(10);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
						Sleep(10);
					}
				}
				//最后一层
			}
		}
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				Sleep(30);
			}
		}
		cct_setcolor();
	}
	if (sj == 6)
	{
		cct_setconsoleborder(40, row + 6, 100, 100);
		cout << "屏幕：" << row + 6 << "行40列" << endl;
		cct_showstr(1, 1, str1, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, 1, str2, 7, 0, 1, 2);
		cct_showstr(1, row + 2, str3, 7, 0, 1, 2);
		cct_showstr(2 * col + 3, row + 2, str4, 7, 0, 1, 2);
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, 1, str5, 7, 0, 1, 2);
		}
		for (int i = 1; i <= col; i++)
		{
			cct_showstr(2 * i + 1, row + 2, str5, 7, 0, 1, 2);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(1, i - 1, str6, 7, 0, 1, 2);
		}
		for (int i = 3; i <= row + 2; i++)
		{
			cct_showstr(2 * col + 3, i - 1, str6, 7, 0, 1, 2);
		}
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
		cct_setcolor();
		if (xiao == 0)
		{
			cct_gotoxy(15, 0);
			cout << "(未找到初始可消除项）";
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 0)
					{
						cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();
		}
		if (xiao == 1)
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{				
					if (color[i][j] == 0)
					{
						cct_showstr(2 * j + 1, i + 1, str7, piccolor[i][j], 0, 1, 2);
					}
					if (color[i][j] == 1)
					{
						cct_showstr(2 * j + 1, i + 1, str8, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();
		}
	}
	if (sj == 7)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "屏幕：" << 2 * row + 5 << "行40列" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					Sleep(10);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//第一层
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//偶数层

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//奇数层

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//最后一层
			}
		}
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		cct_setcolor();
		while (xiao == 1)
		{
			cct_gotoxy(0, 2 * row + 2);
			cout << "按回车键进行消除及下落除0操作...";
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
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
					}
				}
			}
			//消除

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
							piccolor[k + 1][j] = piccolor[k][j];
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
							Sleep(70);
							//下落1
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
							Sleep(70);
							//下落2
						}
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//数字除0

			cct_gotoxy(0, 2 * row + 2);
			cout << "按回车键进行新值填充...           ";
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
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//新值填充
			xiao = 0;
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
		}
		cct_setcolor();
		if (xiao == 0)
		{
			cct_gotoxy(14, 0);
			cout << "(未找到初始可消除项)";
			cct_gotoxy(0, 2 * row + 2);
			cout << "按回车键显示消除提示...        ";
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
			graph_check_clear(row, col, dig, color, piccolor);
			cct_setcolor();
		}
	}
	if (sj == 8)
	{
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "屏幕：" << 2 * row + 5 << "行40列(当前分数：0 右键退出)" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//第一层
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//偶数层

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//奇数层

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//最后一层
			}
		}
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		cct_setcolor();
		while (xiao == 1)
		{
			
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
					}
				}
			}
			//消除

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
							piccolor[k + 1][j] = piccolor[k][j];						
						}
						//将所有颜色下移一层
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
						}
						Sleep(50);
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
						}
						Sleep(50);
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//除0
			
			for (int j = 1; j <= col; j++)
			{
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//新值填充

			xiao = 0;
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
		}
		cct_setcolor();
		if (xiao == 0)
		{
			char str[5] = { "◎" };
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
			//检查是否可以消除

			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();

			int X = 0, Y = 0;
			int ret, maction;
			int keycode1, keycode2;
			int loop = 1;
			char output = 'A';

			cct_setcursor(CURSOR_INVISIBLE);
			cct_enable_mouse();

			while (loop)
			{
				ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
				if (ret == CCT_MOUSE_EVENT)
				{
					if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					{
						break;
					}

					output = 'A';
					cct_gotoxy(0, 2 * row + 2);
					cout << "[当前光标] ";				
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * col - 1 && Y % 2 == 0 && Y <= 18)
					{
						output = 'A' + Y / 2 - 1;
						cout << output << "行" << int((X + 2) / 4) << "列      ";
						
						if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "当前选择" << output << "行" << int((X + 2) / 4) << "列     ";
							Sleep(1000);
							cct_setcursor(CURSOR_VISIBLE_NORMAL);
							break;
						}
						else if (maction == MOUSE_LEFT_BUTTON_CLICK)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "不能选择" << output << "行" << int((X + 2) / 4) << "列     ";
							Sleep(100);
						}
					}
					else
					{
						cct_gotoxy(11, 2 * row + 2);
						cout << "位置非法";
					}

				}
			}

			cct_disable_mouse();	//禁用鼠标
		}
	}
   	if (sj == 9)
	{
		int score = 0;
		cct_setconsoleborder(40, 2 * row + 5, 100, 100);
		cout << "屏幕：" << 2 * row + 5 << "行40列(当前分数：0 右键退出)" << endl;
		for (int i = 1; i <= 2 * row + 1; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (i == 1 && j == 1)
				{
					cct_showstr(0, 1, str1, 7, 0, 1, 2);
					cct_showstr(2, 1, str5, 7, 0, 1, 2);
				}
				if (j != 1 && i == 1)
				{
					cct_showstr(4 * j - 4, 1, str9, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, 1, str5, 7, 0, 1, 2);
				}
				if (i == 1 && j == col)
				{
					cct_showstr(4 * j, 1, str2, 7, 0, 1, 2);
				}
				//第一层
				if (i % 2 == 0)
				{
					cct_showstr(4 * j - 4, i, str6, 7, 0, 1, 2);
					cct_showstr(4 * j - 2, i, str14, 7, 7, 1, 2);
					if (j == col)
					{
						cct_showstr(4 * j, i, str6, 7, 0, 1, 2);
					}
				}
				//偶数层

				if (i % 2 == 1 && i != 1 && i != 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str10, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str11, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str12, 7, 0, 1, 2);
					}
				}
				//奇数层

				if (i == 2 * row + 1)
				{
					if (j == 1)
					{
						cct_showstr(0, i, str3, 7, 0, 1, 2);
						cct_showstr(2, i, str5, 7, 0, 1, 2);
					}
					if (j != 1)
					{
						cct_showstr(4 * j - 4, i, str13, 7, 0, 1, 2);
						cct_showstr(4 * j - 2, i, str5, 7, 0, 1, 2);
					}
					if (j == col)
					{
						cct_showstr(4 * j, i, str4, 7, 0, 1, 2);
					}
				}
				//最后一层
			}
		}
		//画框架
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
		cct_setcolor();
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (color[i][j] == 0)
				{
					cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
				}
				if (color[i][j] == 1)
				{
					cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
				}

			}
		}
		//黑白球上色
		cct_setcolor();
		while (xiao == 1)
		{
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(20);
						cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
						Sleep(200);
						cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
						Sleep(200);
						dig[i][j] = 0;
						score++;
					}
				}
			}
			cct_setcolor();
			//消除
			cct_gotoxy(25, 0);
			cout << score;

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
							piccolor[k + 1][j] = piccolor[k][j];						
						}
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
						}
						Sleep(50);
						for (int k = i - 1; k > times; k--)
						{
							cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
							cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
						}
						Sleep(50);
						times++;
						dig[times][j] = 0;
						color[times][j] = 1;
					}
				}
			}
			cct_setcolor();
			//除0

			for (int j = 1; j <= col; j++)
			{
				for (int i = 1; i <= row; i++)
				{
					if (dig[i][j] == 0)
					{
						dig[i][j] = 1 + rand() % (9);
						if (dig[i][j] >= 1 && dig[i][j] <= 6)
							piccolor[i][j] = int(dig[i][j]);
						else
							piccolor[i][j] = int(dig[i][j]) + 1;
						color[i][j] = 0;
						cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
						Sleep(200);
					}
				}
			}
			cct_setcolor();
			//新值填充

			xiao = 0;
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
		}
		//能消除的
		cct_setcolor();
		if (xiao == 0)
		{
			int loop = 0;
			char str[5] = { "◎" };
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
						loop = 1;
					}

					//dig[i+1][j]标记的情况
					if (dig[i][j - 1] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}

					//dig[i][j+1]标记的情况
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}

					//dig[i][j-1]标记的情况
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j + 1] == dig[i - 1][j] && dig[i][j - 1] != dig[i][j + 1] && dig[i][j] != dig[i - 1][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}

					//上下左右全相等
					if (dig[i - 1][j] == dig[i + 1][j] && dig[i][j - 1] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						color[i - 1][j] = 1;
						color[i][j + 1] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}

					//00X的情况
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i + 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}
					if (j > 2 && dig[i][j - 2] == dig[i][j - 1] && dig[i][j - 1] == dig[i - 1][j] && dig[i][j] != dig[i][j - 1])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

					//X00的情况
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i][j - 1] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i + 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}
					if (j <= col - 2 && dig[i][j + 2] == dig[i][j + 1] && dig[i - 1][j] == dig[i][j + 1] && dig[i][j] != dig[i][j + 1])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

					//X上00的情况
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j - 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i][j + 1] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (i > 2 && dig[i - 2][j] == dig[i - 1][j] && dig[i - 1][j] == dig[i + 1][j] && dig[i - 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i + 1][j] = 1;
						loop = 1;
					}

					//X下00的情况
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j - 1] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j - 1] = 1;
						loop = 1;
					}
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i][j + 1] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i][j + 1] = 1;
						loop = 1;
					}
					if (i <= row - 2 && dig[i + 2][j] == dig[i + 1][j] && dig[i + 1][j] == dig[i - 1][j] && dig[i + 1][j] != dig[i][j])
					{
						color[i][j] = 1;
						color[i - 1][j] = 1;
						loop = 1;
					}

				}
			}
			//检查是否可以消除
			
			for (int i = 1; i <= row; i++)
			{
				for (int j = 1; j <= col; j++)
				{
					if (color[i][j] == 1)
					{
						cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
					}
				}
			}
			cct_setcolor();

			int X = 0, Y = 0;
			int ret, maction;
			int keycode1, keycode2;

			char output = 'A';
			int X1 = 0, Y1 = 0;
			int X2 = 0, Y2 = 0;
			int gameover = 0;

			cct_setcursor(CURSOR_INVISIBLE);
			cct_enable_mouse();

			while (loop)
			{
				ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

				if (ret == CCT_MOUSE_EVENT)
				{
					if (maction == MOUSE_RIGHT_BUTTON_CLICK)
					{
						break;
					}
					//右键退出

					output = 'A';
					cct_gotoxy(0, 2 * row + 2);
					cout << "[当前光标] ";
					if (((X + 1) % 4 == 0 || (X + 2) % 4 == 0) && X <= 4 * col - 1 && Y % 2 == 0 && Y <= 18 && X >= 0)//合法区域
					{
						output = 'A' + Y / 2 - 1;
						cout << output << "行" << int((X + 2) / 4) << "列                                ";

						if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1 && X1 == 0 && Y1 == 0)
						{
							cct_gotoxy(0, 2 * row + 2);
							output = 'A' + Y / 2 - 1;
							cout << "当前选择" << output << "行" << int((X + 2) / 4) << "列                           ";
							Sleep(500);
							X1 = int((X + 2) / 4);
							Y1 = int(Y / 2);
							cct_showstr(4 * X1 - 2, 2 * Y1, str, piccolor[Y1][X1], 7, 1, 2);
							cct_setcolor();
						}
						//选中第一个区域
						else if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 1 && X1 != 0 && Y1 != 0)
						{						
							X2 = int((X + 2) / 4);
							Y2 = int(Y / 2);
							output = 'A' + Y2 - 1;
							if (X1 == X2 && Y1 == Y2)
							{
								output = 'A' + Y2 - 1;
								cct_showstr(4 * X1 - 2, 2 * Y1, str, piccolor[Y1][X1], 0, 1, 2);
								cct_setcolor();
								cct_gotoxy(0, 2 * row + 2);
								cout << "当前选择" << output << "行" << int((X + 2) / 4) << "列                      ";
								cct_setcolor();
								Sleep(200);
								X1 = 0;
								X2 = 0;
								Y1 = 0;
								Y2 = 0;
								continue;
							}
							//选中两次相同的

							else if ((abs(X1 - X2) == 1 && abs(Y1 - Y2) == 0) || (abs(X1 - X2) == 0 && abs(Y1 - Y2) == 1) && color[Y2][X2] == 1)
							{
								
								int m = dig[Y2][X2], n = piccolor[Y2][X2];
								dig[Y2][X2] = dig[Y1][X1];
								dig[Y1][X1] = m;
								piccolor[Y2][X2] = piccolor[Y1][X1];
								piccolor[Y1][X1] = n;
								//交换两组数据

								xiao = 0;
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

								if (xiao == 0)
								{
									dig[Y1][X1] = dig[Y2][X2];
									dig[Y2][X2] = m;
									piccolor[Y1][X1] = piccolor[Y2][X2];
									piccolor[Y2][X2] = n;
									//换回去
									cct_gotoxy(0, 2 * row + 2);
									output = 'A' + Y2 - 1;
									cout << "不能交换" << char('A' + Y1 - 1) << "行" << X1 << "列 <=> " << output << "行" << X2 << "列";
									Sleep(100);

									X1 = 0;
									Y1 = 0;
									X2 = 0;
									Y2 = 0;
									m = 0;
									n = 0;
									//重置X2,Y2条件

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
									//检查是否可以消除
									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
											}
										}
									}
									//提示消除项
									cct_setcolor();
									continue;
								}
								//不能消除
								if (xiao == 1)
								{
									cct_showstr(4 * X1 - 2, 2 * Y1, str7, piccolor[Y1][X1], 0, 1, 2);
									cct_showstr(4 * X2 - 2, 2 * Y2, str7, piccolor[Y2][X2], 0, 1, 2);
									//交换位置
								}
								while (xiao == 1)
								{
									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 0)
											{
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
											}
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str8, piccolor[i][j], 0, 1, 2);
											}

										}
									}
									Sleep(500);
									//上色黑白

									for (int i = 1; i <= row; i++)
									{
										for (int j = 1; j <= col; j++)
										{
											if (color[i][j] == 1)
											{
												cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
												Sleep(20);
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
												Sleep(20);
												cct_showstr(4 * j - 2, 2 * i, str15, piccolor[i][j], 0, 1, 2);
												Sleep(200);
												cct_showstr(4 * j - 2, 2 * i, str14, 7, 7, 1, 2);
												Sleep(200);
												dig[i][j] = 0;
												score++;
											}
										}
									}
									//消除

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
													piccolor[k + 1][j] = piccolor[k][j];												
												}
												for (int k = i - 1; k > times; k--)
												{
													cct_showstr(4 * j - 2, 2 * k + 1, str7, piccolor[k + 1][j], 0, 1, 2);
													cct_showstr(4 * j - 2, 2 * k, str14, 7, 7, 1, 2);
												}
												Sleep(50);
												for (int k = i - 1; k > times; k--)
												{
													cct_showstr(4 * j - 2, 2 * k + 2, str7, piccolor[k + 1][j], 0, 1, 2);
													cct_showstr(4 * j - 2, 2 * k + 1, str5, 7, 0, 1, 2);
												}
												Sleep(50);
												times++;
												dig[times][j] = 0;
												color[times][j] = 1;
											}
										}
									}
									cct_setcolor();
									//除0

									for (int j = 1; j <= col; j++)
									{
										for (int i = 1; i <= row; i++)
										{
											if (dig[i][j] == 0)
											{
												dig[i][j] = 1 + rand() % (9);
												if (dig[i][j] >= 1 && dig[i][j] <= 6)
													piccolor[i][j] = int(dig[i][j]);
												else
													piccolor[i][j] = int(dig[i][j]) + 1;
												color[i][j] = 0;
												cct_showstr(4 * j - 2, 2 * i, str7, piccolor[i][j], 0, 1, 2);
												Sleep(200);
											}
										}
									}
									cct_setcolor();
									//新值填充

									xiao = 0;
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
									cct_setcolor();
								}

								gameover = 0;
								cct_gotoxy(25, 0);
								cout << score << " 右键退出)";
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
								//检查是否可以消除
								for (int i = 1; i <= row; i++)
								{
									for (int j = 1; j <= col; j++)
									{
										if (color[i][j] == 1)
										{
											cct_showstr(4 * j - 2, 2 * i, str, piccolor[i][j], 0, 1, 2);
											gameover = 1;
										}
									}
								}
								//提示消除项
								cct_setcolor();
								//在循环结束之后提示消除项
								X1 = 0;
								X2 = 0;
								Y1 = 0;
								Y2 = 0;
								if (gameover == 0)
								{
									break;
								}
							}
						}
						else if (maction == MOUSE_LEFT_BUTTON_CLICK && color[int(Y / 2)][int((X + 2) / 4)] == 0)
						{
							cct_gotoxy(0, 2 * row + 2);
							cout << "不能选择" << output << "行" << int((X + 2) / 4) << "列                        ";
							Sleep(100);
						}
					}
					else
					{
						cct_gotoxy(11, 2 * row + 2);
						cout << "位置非法                           ";
					}

				}
			}

			cct_disable_mouse();	//禁用鼠标
		}
	}
}
//画出初始结构


void ini_struct(int row, int col, char dig[12][12], char color[12][12], int sj)
{
	cct_setfontsize("新宋体", 28);
	int piccolor[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if (dig[i][j] >= 1 && dig[i][j] <= 6)
			{
				piccolor[i][j] = int(dig[i][j]);
			}
			else
			{
				piccolor[i][j] = int(dig[i][j]) + 1;
			}
		}
	}
	//给其上对应颜色

	draw_struc(row, col, dig, color, piccolor, sj);
	if (sj == 4)
	{
		cct_gotoxy(1, row + 3);
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
	if (sj == 5)
	{
		cct_gotoxy(0, 2 * row + 2);
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
	if (sj == 6)
	{
		cct_gotoxy(1, row + 3);
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
	if (sj == 7)
	{
		cct_gotoxy(0, 2 * row + 2);
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
	if (sj == 8)
	{
		cct_gotoxy(0, 2 * row + 2);
		jieshu();
	}
	if (sj == 9)
	{
		cct_gotoxy(0, 2 * row + 2);
		jieshu();
	}
}


