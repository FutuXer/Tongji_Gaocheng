/* 2353726 信01 付煜超 */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

void case1();
void case2(double a, double b, double c);
void case3(double a, double b, double c);
void case4(double a, double b, double c);

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;

	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;

	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	double delta = b * b - 4 * a * c;
	if (fabs(delta) < 1e-6)
		delta = 0;
	if (a == 0)
		case1();
	else
	{
		if (delta > 0)
			case2(a, b, c);
		if (delta == 0)
			case3(a, b, c);
		if (delta < 0)
			case4(a, b, c);
	}

	return 0;
}
