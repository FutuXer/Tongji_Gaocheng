/* 2353726 信01 付煜超 */
#include <iostream>
using namespace std;

void max(int b, int c)
{
	cout << "max=" << (b > c ? b : c) << endl;
}

void max(int b, int c, int d)
{
	int m = (b > c ? b : c);
	cout << "max=" << (m > d ? m : d) << endl;
}

void max(int b, int c, int d, int e)
{
	int m = (b > c ? b : c);
	int n = (d > e ? d : e);
	cout << "max=" << (m > n ? m : n) << endl;
}

int main()
{
	int a, b, c, d, e;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> a;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (a != 2 && a != 3 && a != 4)
		{
			cout << "个数输入错误" << endl;
			break;
		}
		if (a == 2)
		{
			cin >> b >> c;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (b < 1 || c < 1)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			max(b, c);
			break;
		}
		if (a == 3)
		{
			cin >> b >> c >> d;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (b < 1 || c < 1 || d < 1)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			max(b, c, d);
			break;
		}
		if (a == 4)
		{
			cin >> b >> c >> d >> e;
			if (cin.good() == 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if (b < 1 || c < 1 || d < 1 || e < 1)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			max(b, c, d, e);
			break;
		}
	}
	return 0;
}