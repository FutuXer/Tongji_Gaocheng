/* 2353726 付煜超 信01 */
#include <iostream>
#include <conio.h>
#include "7-b2.h"
#include "cmd_console_tools.h"

using namespace std;
/* 1、按需加入头文件
   2、不允许定义全部变量，包括静态全局，但不显示const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int fun()
{
     //仅为示例，不需要可删除
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    int titlelen = strlen(original_para->title);
    int X = original_para->start_x;
    int Y = original_para->start_y;
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    int x = 0, y = 0;
    int flag = 0;
    int width = original_para->width;
    int high = original_para->high;
    int futuxer = 0; 
    while (menu[futuxer][0] != NULL)
    {
        futuxer++;
    }
    if (high > futuxer)
    {
        high = futuxer;
    }
    int chinstr = 0;
    if (width<=titlelen)
    {
        width = titlelen;
    }
    if (width%2==1)
        width++;
    int choose = 0;
    int upborder = 0;
    int downborder = high;
    cct_setcolor(original_para->bg_color, original_para->fg_color);
    cct_gotoxy(original_para->start_x, original_para->start_y);
    cout << "╔";
    if (titlelen % 2 == 0)
    {
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "═";
        cout << original_para->title;
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "═";
        if (((width - titlelen) / 2) % 2 != 0)
            cout << "═";
    }
    if (titlelen % 2 == 1)
    {
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "═";
        cout << original_para->title << " ";
        for (int i = 1; i <= (width - titlelen) / 4; i++)
            cout << "═";
        if (((width - titlelen) / 2) % 2 != 0)
            cout << "═";
    }
    cout << "╗";
    int sj = 0;  
    cct_gotoxy(X, Y + high + 1);
    cout << "╚";
    for (int i = 1; i <= width / 2; i++)
    {
        cout << "═";
    }
    cout << "╝";
    while (1)
    {
        sj = 0;
        for (int i = upborder; i < downborder; i++)
        {
            flag = 0;
            cct_gotoxy(X, Y + sj + 1);
            cout << "║";
            chinstr = 0;
            for (int j = 0; j < width; j++)
            {
                if (menu[i][j] < 0 || menu[i][j]>127)
                    chinstr++;
            }
            if (chinstr % 2 == 1)
            {
                for (int k = 0; k < width - 1; k++)
                {
                    if (choose == i)
                    {
                        cct_setcolor(original_para->fg_color, original_para->bg_color);
                    }
                    else
                    {
                        cct_setcolor(original_para->bg_color, original_para->fg_color);
                    }
                    cct_getxy(x, y);
                    if (x == cols - 1 && x == buffer_cols - 1)
                    {
                        cout << " ";
                        flag = 1;
                    }
                    if (menu[i][k] == '\0')
                        cout << " ";
                    else
                        cout << menu[i][k];
                    cct_setcolor(original_para->bg_color, original_para->fg_color);
                }
                if (flag == 1)
                {
                    cout << '\b';
                }
                cout << " ";
            }
            else if (chinstr % 2 == 0)
            {
                for (int k = 0; k < width; k++)
                {
                    if (choose == i)
                    {
                        cct_setcolor(original_para->fg_color, original_para->bg_color);
                    }
                    else
                    {
                        cct_setcolor(original_para->bg_color, original_para->fg_color);
                    }
                    cct_getxy(x, y);
                    if (x == cols - 1 && x == buffer_cols - 1)
                    {
                        cout << " ";
                        flag = 1;
                    }
                    if (menu[i][k] == '\0')
                        cout << " ";
                    else
                        cout << menu[i][k];
                    cct_setcolor(original_para->bg_color, original_para->fg_color);
                }
                if (flag == 1)
                {
                    cout << '\b';
                }
            }
            cout << "║";
            sj++;
        }
        while (1)
        {
            char ch = _getch();
            if (ch == 72 && choose != 0)
            {
                if (choose == upborder)
                {
                    upborder--;
                    downborder--;
                }
                choose--;
                break;
            }
            else if (ch == 80 && choose != 9)
            {
                if (choose == downborder - 1)
                {
                    upborder++;
                    downborder++;
                }
                choose++;
                break;
            }
            else if (ch == '\r')
            {
                return choose + 1;
            }
            else
            {
                continue;
            }
        }
    }
	return 0; //按需返回
}
