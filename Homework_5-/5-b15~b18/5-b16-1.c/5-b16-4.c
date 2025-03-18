//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input(char num[][8], char name[][9], int grade[], int n)
{
	printf("请输入第%d个人的学号、姓名、成绩\n", n + 1);
	scanf("%s %s %d", num[n], name[n], &grade[n]);
}

void rank(char num[][8], char name[][9], int grade[])
{
	char number[8] = { 0 };
	char name0[9] = { 0 };
	int marks = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (grade[j] < grade[j + 1])
			{
				for (int k = 0; k < 8; k++)
					number[k] = num[j][k];
				for (int k = 0; k < 9; k++)
					name0[k] = name[j][k];
				marks = grade[j];
				for (int k = 0; k < 8; k++)
					num[j][k] = num[j + 1][k];
				for (int k = 0; k < 9; k++)
					name[j][k] = name[j + 1][k];
				grade[j] = grade[j + 1];
				for (int k = 0; k < 8; k++)
					num[j + 1][k] = number[k];
				for (int k = 0; k < 9; k++)
					name[j + 1][k] = name0[k];
				grade[j + 1] = marks;
			}
		}
	}
}

void output(char num[][8], char name[][9], int grade[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("%s %s %d\n", name[i], num[i], grade[i]);
	}
}

int main()
{
	char num[10][8] = { 0 };
	char name[10][9] = { 0 };
	int grade[10] = { 0 };
	int n = 0;
	for (n = 0; n < 10; n++)
	{
		input(num, name, grade, n);
	}
	rank(num, name, grade);
	printf("\n");
	printf("全部学生(成绩降序):\n");
	output(num, name, grade);

	return 0;
}