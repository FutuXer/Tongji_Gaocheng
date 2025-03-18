//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n"); 
	int a;
	scanf("%d", &a);
    int b = a / 10000;
	int c = a / 1000-10*b;
	int d = a / 100-10*c-100*b;
	int e = a / 10-1000*b-100*c-10*d;
	int f = a - 10000 * b-1000*c-100*d-10*e;
	printf("万位 : %d\n", b);
	printf("千位 : %d\n", c);
	printf("百位 : %d\n", d);
	printf("十位 : %d\n", e);
	printf("个位 : %d\n", f);
	




	return 0;
}