//2353726 ÐÅ01 ¸¶ìÏ³¬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i, j;
	for (int i = 1; i <= 9; i++)
	{
		for (j=1; j <= i; j++)
		{
			if (i*j<10)
			{
				printf("%dx%d=%d   ", j, i, i * j);
			}
			else
			{
				printf("%dx%d=%d  ", j, i, i * j);
			}
			if (i==j)
			{
				printf("\n");
			}
		}
	}
	return 0;
}