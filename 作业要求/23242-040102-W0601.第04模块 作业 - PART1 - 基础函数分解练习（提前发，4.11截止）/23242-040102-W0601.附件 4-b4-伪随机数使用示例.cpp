/* 学号 姓名 班级 */
#include <iostream>
#include <time.h>
#include <windows.h>
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
	/* srand函数用于生成伪随机数的种子，只需在程序开始时执行一次即可
	   下面的两个srand，根据需要打开其中的一个，注释掉另一个，观察运行结果
	*/
	srand((unsigned int)(time(0)));
//	srand(111); //可以替换为其它数字，自行替换并观察结果 

	/*生成10个伪随机数 */ 
	for (int i=0; i<10; i++) 
	    cout << rand() << endl;

	return 0;
}

