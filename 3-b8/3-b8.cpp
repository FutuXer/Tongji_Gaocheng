//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	while (1)
	{
		cout << "请输入x的值[-10~ +65]" << endl;
		double x;
		int result = 1;
		double n = 0, a = 0, b = 1;
		cin >> x;
		if (x < -10 || x>65)
		{
			cout << "输入非法,请重新输入" << endl;
			continue;
		}
		while (fabs(b) >= 1e-6)
		{
			a = a + b;
			n = n + 1;
			b = b * x / n;
		}
		std::cout << "e^" << x << "=" << std::setprecision(10) << a << std::endl;
		break;
	}
	return 0;
}