/* 2353726 信01 付煜超 */
#include <iostream>
#include <iomanip>

using namespace std;
int a[10][10] = { 0 };
int P[10][4][4] = { 0 };

void area()
{
	int i; 
	int j = 1; 
	int k = 1; 
	int m, n;
	for (i = 1; i < 10; i++)
	{
		if (i % 3 == 0)
		{
			m = 3;
		}
		else
			m = i % 3;
		for (j = 1; j < 10; j++)
		{
			if (j % 3 == 0)
			{
				j = 3;
			}
			else
			{
				n = j % 3;
			}
			if (i < 4)
			{
				k = j / 3 + 1;
			}
			else if (i > 3 && i < 7)
			{
				k = 4 + j / 3;
			}
			else if (i > 6 && i < 10)
			{
				k = 7 + j / 3;
			}
			P[k][m][n] = a[i][j];
		}
	}
}

int judgerow()
{
	int i = 1;
	int j = 1;
	int k = 1;
	for ( i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 1; k < j; k++)
			{
				if (a[i][j] == a[i][k])
				{
					return 1;
				}				
			}

		}
	}
	return 0;
}

int judgecolumn()
{
	int i = 1;
	int j = 1;
	int k = 1;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 1; k < j; k++)
			{
				if (a[j][i] == a[k][i])
				{
					return 1;
				}
				else
					return 2;
			}

		}
	}
	return 0;
}

int judegearea()
{
	int i = 1;
	int j = 1;
	int k = 1;
	int m = 1;
	int n = 1;
	for (k = 1; k < 10; k++)
	{
		for ( i = 1; i < 4; i++)
		{
			for (j = 1; j < 4; j++);
			{
				for (m = 1; m < i; m++)
				{
					for (n = 1; n < j; n++)
					{
						if (P[k][m][n] == P[k][i][j])
						{
							return 1;
						}
					}

				}

			}

		}
	}
	return 0;
}

int main()
{
	int i = 1;
	int j = 1;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			while (1)
			{
				cin >> a[i][j];
				if (a[i][j] > 9 || a[i][j] < 1)
				{
					cout << "请重新输入第" << i << "行" << j << "列(行列均从1开始计数)的值" << endl;
				}
				else if (cin.good() == 0)
				{
					cin.clear();
					cin.ignore(1024, '\n');//1 1 1 1 1 1 1 1 1
				}
				else
					break;
			}
		}

	}
	void area();
	int row = judgerow();
	int column = judgecolumn();
	int are = judegearea();
	if (row == 0 && column == 0 && are == 0)
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}
	
	return 0;
}