/* 2353726 信01 付煜超 */
#include <iostream>
using namespace std;


int main()
{
	bool x = 1;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int a[21];
	for (int i = 0; i < 21 ;i++)
	{
		cin >> a[i];
		if (a[0] <= 0) 
		{
			x = 0;
			cout << "无有效输入" << endl;
		}
		if (a[i] <= 0)
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(1024, '\n');
	if (x == 1)
	{
		cout << "原数组为: " << endl;
		for (int i = 0; i < 20; i++)
		{
			if (a[i] > 0)
			{
				cout << a[i] << " ";
			}
		}
		cout << endl;
		cout << "请输入要插入的正整数" << endl;
		cin >> a[20];
		cout << "插入后的数组为：" << endl;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20 - i; j++)
			{
				if (a[j] > a[j + 1])
				{
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
		for (int i = 0; i < 21; i++)
		{
			if (a[i] > 0)
			{
				cout << a[i] << " ";
			}
		}
	}
	cout << endl;
	return 0;
}