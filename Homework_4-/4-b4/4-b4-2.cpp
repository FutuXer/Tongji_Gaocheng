/* 2353726 付煜超 信01 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度
const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
void move_by_ijkl(int a)
{
	int x = 34, y = 8;
	while (a == 49)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		// 根据按下的键值移动光标
		if ((key1 == 73 || key1 == 105) && y > 1)  // 上箭头
			y--;
		else if ((key1 == 75 || key1 == 107) && y < 17)  // 下箭头
			y++;
		else if ((key1 == 74 || key1 == 106) && x > 1)  // 左箭头
			x--;
		else if ((key1 == 76 || key1 == 108) && x < 69)  // 右箭头
			x++;
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
	while (a == 50)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		// 根据按下的键值移动光标
		if ((key1 == 73 || key1 == 105) && y > 1)  // 上箭头
			y--;
		else if ((key1 == 73 || key1 == 105) && y == 1)
			y = 16;

		if ((key1 == 75 || key1 == 107) && y < 17)  // 下箭头
			y++;
		else if ((key1 == 75 || key1 == 107) && y == 17)
			y = 2;

		if ((key1 == 74 || key1 == 106) && x > 1)  // 左箭头
			x--;
		else if ((key1 == 74 || key1 == 106) && x == 1)
			x = 68;

		if ((key1 == 76 || key1 == 108) && x < 69)  // 右箭头
			x++;
		else if ((key1 == 76 || key1 == 108) && x == 69)
			x = 2;
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
	while (a == 53)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 == 0 || key1 == 224)
		{
			int key2 = _getch();
			continue;
		}
		if ((key1 == 73 || key1 == 105) && y > 1)  // 上箭头
			y--;
		else if ((key1 == 75 || key1 == 107) && y < 17)  // 下箭头
			y++;
		else if ((key1 == 74 || key1 == 106) && x > 1)  // 左箭头
			x--;
		else if ((key1 == 76 || key1 == 108) && x < 69)  // 右箭头
			x++;
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
	while (a == 54)
	{
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 == 0 || key1 == 224)
		{
			int key2 = _getch();
			continue;
		}
		if ((key1 == 73 || key1 == 105) && y > 1)  // 上箭头
			y--;
		else if ((key1 == 73 || key1 == 105) && y == 1)
			y = 16;

		if ((key1 == 75 || key1 == 107) && y < 17)  // 下箭头
			y++;
		else if ((key1 == 75 || key1 == 107) && y == 17)
			y = 2;

		if ((key1 == 74 || key1 == 106) && x > 1)  // 左箭头
			x--;
		else if ((key1 == 74 || key1 == 106) && x == 1)
			x = 68;

		if ((key1 == 76 || key1 == 108) && x < 69)  // 右箭头
			x++;
		else if ((key1 == 76 || key1 == 108) && x == 69)
			x = 2;		
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
}

void move_by_arrow(int a)
{
	int x = 34, y = 8;
	while (a == 51)
	{	
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 != 0 && key1 != 224)
		{
			continue;
		}
		int key2 = _getch();
		// 根据按下的键值移动光标
		if (key2 == 72 && y > 1)  // 上箭头
			y--;
		else if (key2 == 80 && y < 17)  // 下箭头
			y++;
		else if (key2 == 75 && x > 1)  // 左箭头
			x--;
		else if (key2 == 77 && x < 69)  // 右箭头
			x++;
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
	while (a == 52)
	{	
		int key1 = _getch();
		if (key1 == 81 || key1 == 113)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int back = _getch();
				if (back == 13)
					break;
				else
					continue;
			}
			break;
		}
		if (key1 == 32)
		{
			cout << " ";
			gotoxy(hout, x, y);
			continue;
		}
		if (key1 != 0 && key1 != 224)
		{
			continue;
		}
		int key2 = _getch();
		// 根据按下的键值移动光标
		if (key2 == 72 && y > 1)  // 上箭头
			y--;
		else if (key2 == 72 && y == 1)
			y = 16;

		if (key2 == 80 && y < 17)  // 下箭头
			y++;
		else if (key2 == 80 && y == 17)
			y = 2;

		if (key2 == 75 && x > 1)  // 左箭头
			x--;
		else if (key2 == 75 && x == 1)
			x = 68;

		if (key2 == 77 && x < 69)  // 右箭头
			x++;
		else if (key2 == 77 && x == 69)
			x = 2;
		// 移动光标到新位置
		gotoxy(hout, x, y);
	}
}
//菜单函数
void menu(int me)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);
	/* 显示初始的边框及其中的随机字符 */
	init_border(hout);
	//暂停
	int x = 34;
	int y = 8;
	gotoxy(hout, x, y);
	int a = me;
	if (a == 49 || a == 50 || a == 53 || a == 54)
	{
		move_by_ijkl(a);
	}
	if (a == 51 || a == 52)
	{
		move_by_arrow(a);
	}
	
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	while (1)
	{
		cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
		cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
		cout << "3.用箭头键控制上下左右，边界停止" << endl;
		cout << "4.用箭头键控制上下左右，边界回绕" << endl;
		cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,左箭头禁用）" << endl;
		cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,左箭头禁用）" << endl;
		cout << "0.退出" << endl;
		cout << "[请选择0-6] ";
		int me = _getch();
		if (me == 48)
		{
			break;
		}
		else
		{
			menu(me);
			cls(hout);
		}
	}


	return 0;
}