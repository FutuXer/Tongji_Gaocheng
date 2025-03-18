//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double a;
	cin >> a;
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
	int n = int(10 * c);
	int o = int(100 * c) - 10 * n;
	int p = int(1000 * c) - 100 * n - 10 * o;
	int g0, h0, i0, k0, l0, m0, n0, o0, p0;
	if (f + h + i + j + k + l + m + n == 0 || f + h + i + j == 0 || h + i + j == 0)
	{
		g0 = 0;
	}
	else if (e + f == 0)
	{
		g0 = 0;
	}
	else
	{
		g0 = 1;
	}
	if (g == 0)
	{
		h0 = 0;
	}
	else if (i == 0 && j == 0)
	{
		h0 = 0;
	}
	else
	{
		h0 = 1;
	}
	if (h == 0)
	{
		i0 = 0;
	}
	else if (j == 0)
	{
		i0 = 0;
	}
	else
	{
		i0 = 1;
	}
	if (a > 9999.99 && l + m + n > 0)
	{
		k0 = 1;
	}
	else if (a > 9999.99 && l + m + n == 0)
	{
		k0 = 0;
	}
	else
	{
		k0 = 0;
	}
	if (k == 0)
	{
		l0 = 0;
	}
	else if (m == 0 && n == 0)
	{
		l0 = 0;
	}
	else
	{
		l0 = 1;
	}
	if (l == 0)
	{
		m0 = 0;
	}
	else if (n == 0)
	{
		m0 = 0;
	}
	else
	{
		m0 = 1;
	}
	if (e + f + g + h + i + j + k + l + m == 0 && o + p == 0)
	{
		n0 = 1;
	}
	else
	{
		n0 = 0;
	}
	if (e + f + g + h + i + j + k + l + m + n > 0 && p > 0)
	{
		o0 = 1;
	}
	else
	{
		o0 = 0;
	}
	daxie(e, 0);
	if (e>0)
		cout << "拾";
	daxie(f, 0);
	if (f+e>0)
		cout << "亿";
	daxie(g, g0);
	if (g > 0)
		cout << "仟";
	daxie(h, h0);
	if (h > 0)
		cout << "佰";
	daxie(i, i0);
	if (i > 0)
		cout << "拾";
	daxie(j, 0);
	if (g > 0 || h > 0 || i > 0 || j > 0)
		cout << "万";
	daxie(k, k0);
	if (k > 0)
		cout << "仟";
	daxie(l, l0);
	if (l > 0)
		cout << "佰";
	daxie(m, m0);
	if (m > 0)
		cout << "拾";
	daxie(n, n0);
	if (e + f + g + h + i + j + k + l + m + n == 0 && o + p > 0)
	{
	}
	else
	{
		cout << "圆";
	}
	if (o == 0 && p == 0)
	{
		cout << "整" << endl;
	}
	else
	{
		daxie(o, o0);

	}
	if (o > 0)
	{
		cout << "角";
	}
	daxie(p, 0);
	if (p > 0)
	{
		cout << "分" << endl;
	}
	return 0;
}

