//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("请输入三角形的两边及其夹角（角度）\n");
	const double pi = 3.14159;
	int a, b, c;
	scanf("%d %d %d/n", &a, &b, &c);
	float x = (float)sin(c * pi / 180);
	printf("三角形的面积为 : %.3f\n", (float)0.5 * a * b * x);


	return 0;
}