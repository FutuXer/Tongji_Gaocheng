/* 2353726 付煜超 信01 */
#include <iostream>
#include "magic_ball.h"
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	while (1)
	{
		cct_setfontsize("新宋体", 16);
		cct_setconsoleborder(120, 30, 200, 200);
		int judge = 0;
		judge = menu();
		if (judge > '9' || judge < '0')
		{
			continue;
		}
		int sj = 0;
		sj = int(judge) - 48;
		if (judge == 48)
		{
			break;
		}
		else if (judge == 49 || judge == 50 || judge == 51 || judge == 52 || judge == 53 || judge == 54 || judge == 55 || judge == 56 || judge == 57)
		{
			int row, col;
			cct_cls();
			while (1)
			{
				cout << "请输入行数(5-9)：" << endl;
				cin >> row;
				if (cin.good() == 0)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (row < 5 || row>9)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				break;
			}
			while (1)
			{
				cout << "请输入列数(5-9)：" << endl;
				cin >> col;
				if (cin.good() == 0)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				if (col < 5 || col>9)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				break;
			}
			cout << endl;
			dig_ini(row, col, sj);
		}
		else
		{
			continue;
		}
	}
	return 0;
}

/*四种线型的框架，每种11个元素，每个元素均为一个中文字符（2字节）
		双线框架："╔", "╚", "╗", "╝", "═", "║", "╦", "╩", "╠", "╣", "╬"
		单线框架："┏", "┗", "┓", "┛", "━", "┃", "┳", "┻",  "┣", "┫", "╋"
		横双竖单: "╒", "╘", "╕", "╛", "═", "│", "╤", "╧", "╞", "╡", "╪"
		横单竖双："╓", "╙", "╖", "╜", "─", "║", "╥", "╨", "╟", "╢", "╫"
	

	双线框架使用样例（可自行替换为其它线型）
	   ╔═╦═╗
	   ║  ║  ║
	   ╠═╬═╣
	   ║  ║  ║
	   ╚═╩═╝
cout << "╔═╦═╗" << endl;
cout << "║  ║  ║" << endl;
cout << "╠═╬═╣" << endl;
cout << "║  ║  ║" << endl;
cout << "╚═╩═╝" << endl; 
*/