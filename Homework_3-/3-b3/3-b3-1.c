//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[0-100亿)间的数字:\n");
    double a;
    scanf("%lf", &a);
    double x = a + 1e-6;
    int b = (int)(x / 10);
    double c = x / 10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g - 10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i - 10 * j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = (int)(10 * c);
    int o = (int)(100 * c) - 10 * n;
    int p = (int)(1000 * c) - 100 * n - 10 * o;
    printf("十亿位 : %d\n", e);
    printf("亿位   : %d\n", f);
    printf("千万位 : %d\n", g);
    printf("百万位 : %d\n", h);
    printf("十万位 : %d\n", i);
    printf("万位   : %d\n", j);
    printf("千位   : %d\n", k);
    printf("百位   : %d\n", l);
    printf("十位   : %d\n", m);
    printf("圆     : %d\n", n);
    printf("角     : %d\n", o);
    printf("分     : %d\n", p);

	
	





	return 0;
}