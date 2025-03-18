/* 班级 学号 姓名 */
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、不允许添加其它函数
   ---------------------------------------------------------------------
*/

#define		N	20

/***************************************************************************
  函数名称：
  功    能：将有n个元素的数组向后移动m个位置
  输入参数：int *a：数组
            int n ：数组中有效数字的个数
            int m ：要移动的位置
  返 回 值：
  说    明：
 ***************************************************************************/
void move_data(int *a, const int n, const int m)
{
	/* 除这三个变量外，本函数不再运行定义任何形式的变量
	     如果不用，允许删除，但不得增加或替换为其它形式的变量
	    包括for(int i=0; )形式的新变量定义同样禁止 */
	int t, *p, *q;

	/* 函数的实现部分，不允许任何形式的[]出现 */

}

/***************************************************************************
  函数名称：
  功    能：向数组中输入n个元素
  输入参数：int *a：数组
            int n ：要输入的数字个数
  返 回 值：
  说    明：
 ***************************************************************************/
void input(int *a, const int n)
{
	int *p;  //本函数只允许定义这一个指针变量，不再允许定义任何形式的变量，包括for(int i=0; )等形式

	/* 函数的实现部分，不允许任何形式的[]出现 */

}

/***************************************************************************
  函数名称：
  功    能：将数组中的n个元素输出
  输入参数：int *a：数组
            int n ：要输出的数字个数
  返 回 值：
  说    明：
 ***************************************************************************/
void output(int *a, const int n)
{
	int *p;  //本函数只允许定义这一个指针变量，不再允许定义任何形式的变量，包括for(int i=0; )等形式

	/* 函数的实现部分，不允许任何形式的[]出现 */
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：除允许补全含有...的四行外，其余不准改动
***************************************************************************/
int main()
{
	int a[N], m, n;

	printf("请输入整数的数量n[%d-%d]\n", N / 2, N);
	scanf("%d", &n);

	printf("请输入%d个整数\n", n);
	input(...);

	printf("输入的整数序列为\n");
	output(...);

	printf("请输入向后移动的位置m[1..2^31-1]\n");
	scanf("%d", &m);

	move_data(...);

	printf("移动后的整数序列为\n");
	output(...);

	return 0;
}
