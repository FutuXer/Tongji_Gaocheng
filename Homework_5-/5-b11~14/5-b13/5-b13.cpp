//2353726 ÐÅ01 ¸¶ìÏ³¬
#include <iostream>
#include <ctime>

using namespace std;
	

int main()
{
	char a[12][28] = { 0 };
	srand(static_cast<unsigned int>(time(nullptr)));


	for (int i = 0; i < 50; i++)
	{
		int m, n;
		while (true)
		{
			m = rand() % (10);
			n = rand() % (26);
			if (m < 1 || m>10 || n < 1 || n>26)
			{
				continue;
			}
			if (a[m][n] != '*')
			{
				a[m][n] = '*';
				break;
			}
			else
			{
				continue;
			}
		}
	}

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			if (a[i][j] != '*')
			{
				for (int x = j - 1; x <= j + 1; x++)
				{
					if (a[i - 1][x] == '*')
					{
						a[i][j]++;
					}
					if (a[i + 1][x] == '*')
					{
						a[i][j]++;
					}				
				}
				if (a[i][j - 1] == '*')
				{
					a[i][j]++;
				}
				if (a[i][j + 1] == '*')
				{
					a[i][j]++;
				}
			}
		}
	}



	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 27; j++)
		{
			if (a[i][j] == '*')
			{
				cout << a[i][j] << " ";
			}
			else
			{
				cout << int(a[i][j]) << " ";
			}
		}
		cout << endl;
	}

	cout << " " << endl;
	return 0;
}

