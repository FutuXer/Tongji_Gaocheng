/* 2353726 信01 付煜超 */
#include <iostream>
using namespace std;

//87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
int main()
{
	int a[1000];
	int i = 0;
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	for (i = 0; i < 1000; i++)
	{
		cin >> a[i];
		if (a[0] < 0)
		{
			cout << "无有效输入" << endl;
			break;
		}
		if (a[i] < 0)
		{
			break;
		}
	}
	if (a[0] >= 0)
	{
		cout << "输入的数组为:" << endl;
		for (int j = 0; j < i; j++)
		{
			cout << a[j] << " ";
			if ((j + 1) % 10 == 0)
				cout << endl;
		}
		cout << endl;
		cout << "分数与名次的对应关系为:" << endl;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i - j; k++)
			{
				if (a[k] < a[k + 1])
				{
					int t = a[k];
					a[k] = a[k + 1];
					a[k + 1] = t;
				}
			}
		}
		int rank = 1;
		int num = 1;
		int m = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] == a[j + 1])
			{
				cout << a[j] << " " << rank << endl;
				num = num + 1;
			}
			if (a[j] != a[j + 1])
			{
				cout << a[j] << " " << rank << endl;
				num = num + 1;
				rank = num;
			}
		}
	}



}