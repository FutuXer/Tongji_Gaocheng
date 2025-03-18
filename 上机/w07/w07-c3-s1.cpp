/* 2353726 信01 付煜超 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出位数、正序、逆序
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
void output(int k)
{
	int wan, qian, bai, shi, ge, a, b, c, d, e;
	wan = int(k / 10000);
	qian = int(k / 1000) - 10*wan;
	bai = int(k / 100) - 100 * wan - 10 * qian;
	shi = int(k / 10) - 1000 * wan - 100 * qian - 10 * bai;
	ge = k - 10000 * wan - 1000 * qian - 100 * bai - 10 * shi;
	if (wan > 0)
		a = 1;
	else
		a = 0;
	if (a > 0 || qian > 0)
		b = 1;
	else
		b = 0;
	if (bai > 0 || a + b > 0)
		c = 1;
	else
		c = 0;
	if (shi > 0 || a + b + c > 0)
		d = 1;
	else
		d = 0;
		e = 1;
	cout << a + b + c + d + e << "位数" << endl;
	cout << "每位数字分别是 : " << endl;
	if (a == 1)
		cout << wan << " ";
	if (b == 1)
		cout << qian << " ";
	if (c == 1)
		cout << bai << " ";
	if (d == 1)
		cout << shi << " ";
		cout << ge << endl;
	cout << "逆序输出的每位数字分别是 : " << endl;
	cout << ge << " ";
	if (d == 1)
		cout << shi << " ";
	if (c == 1)
		cout << bai << " ";
	if (b == 1)
		cout << qian << " ";
	if (a == 1)
		cout << wan << endl;
}

/***************************************************************************
  函数名称：
  功    能：重复输入，直到取得[0..99999]之间的整数后返回
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
int input(void)
{
	int k;
	while (true)
	{
		cout << "请输入一个[0..99999]间的整数" << endl;
		cin >> k;
	
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (k >= 0 && k <= 99999)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	return k;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	int k;

	k = input();
	output(k);
	return 0;
}