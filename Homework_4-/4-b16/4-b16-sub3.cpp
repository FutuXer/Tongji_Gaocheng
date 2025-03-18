/* 2353726 信01 付煜超 */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void case3(double a, double b, double c)
{
	double x;
	x = (-b) / (2 * a);
	if (x == -0)
	{
		x = 0;
	}
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x << endl;
}