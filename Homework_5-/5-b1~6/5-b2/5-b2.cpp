/* 2353726 ÐÅ01 ¸¶ìÏ³¬ */
#include <iostream>
using namespace std;


int main()
{
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = 0;
	}
	for (int i = 1; i < 101; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if ((j + 1) % i == 0)
			{
				if (a[j] == 0)
				{
					a[j] = 1;
				}
				else if (a[j] == 1)
				{
					a[j] = 0;
				}
			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (a[i] == 1)
		{
			cout << i + 1 << " ";
		}
	}
	cout << '\b';
	cout << endl;
	return 0;
}