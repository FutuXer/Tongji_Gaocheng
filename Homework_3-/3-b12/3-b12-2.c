//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1)
	{
		printf("请输入x的值[0-100] : ");
		ret = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (ret == 1 && (x >= 0 && x <= 100))
			break;
		if (ret==0)
		{
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF);
			continue;
		}
		else
		{
			continue;
		}
	}

	printf("cin.good()=%d x=%d\n", ret, x);

	return 0;
}