/* 2353726 信01 付煜超 */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void case1()
{
	cout << "不是一元二次方程" << endl;
}

void case2(double a, double b, double c)
{
	double x1, x2;
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	cout << "有两个不等实根：" << endl;
	if (x1 > x2) {
		cout << "x1=" << x1 << endl;
		cout << "x2=" << x2 << endl;
	}
	else {
		cout << "x1=" << x2 << endl;
		cout << "x2=" << x1 << endl;
	}
}

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

void case4(double a, double b, double c)
{
	cout << "有两个虚根：" << endl;
	double shibu = -b / (2 * a);
	double xubu = fabs(sqrt(-b * b + 4 * a * c) / (2 * a));
	if (fabs(xubu - 1) < 1e-6)//虚部为正负一的情况
	{
		if (fabs(shibu) > 1e-6)
		{
			cout << "x1=" << shibu << "+" << "i" << endl;
			cout << "x2=" << shibu << "-" << "i" << endl;
		}
		else//实部为0的情况
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-i" << endl;
		}
	}
	else if (fabs(shibu) < 1e-6)
	{
		cout << "x1=" << xubu << "i" << endl;
		cout << "x2=-" << xubu << "i" << endl;
	}
	else
	{
		cout << "x1=" << shibu << "+" << xubu << "i" << endl;
		cout << "x2=" << shibu << "-" << xubu << "i" << endl;
	}

}