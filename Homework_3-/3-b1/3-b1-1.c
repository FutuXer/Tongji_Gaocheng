//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入半径和高度\n");
	const double pi = 3.14159;
	double a;
	double b;
	scanf("%lf %lf", &a, &b);
	printf("圆周长     : %.2lf\n",2*pi*a);
	printf("圆面积     : %.2lf\n",pi*a*a);
	printf("圆球表面积 : %.2lf\n",4*pi*a*a);
	printf("圆球体积   : %.2lf\n",4*pi*a*a*a/3);
	printf("圆柱体积   : %.2lf\n",pi*a*a*b);





	return 0;
}