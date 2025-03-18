/* 2353726 信01 付煜超 */
#include <iostream>
#include<limits.h>
#include<cmath>
using namespace std;

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