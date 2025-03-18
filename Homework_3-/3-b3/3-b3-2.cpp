//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "请输入一个[1-100亿)之间的数字:" << endl;
	double a;
    cin >> a;
    double x = a + 1e-6;
	int b = (int)(x / 10);
	double c = x/10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g -10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h-10*i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i-10*j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = int(10*c);
    int o = int(100 * c) - 10 * n;
    int p = int(1000 * c) - 100 * n - 10 * o;




    cout << "十亿位 : " << e << endl;
    cout << "亿位   : " << f << endl;
    cout << "千万位 : " << g << endl;
    cout << "百万位 : " << h << endl;
    cout << "十万位 : " << i << endl;
    cout << "万位   : " << j << endl;
    cout << "千位   : " << k << endl;
    cout << "百位   : " << l << endl;
    cout << "十位   : " << m << endl;
    cout << "圆     : " << n << endl;
    cout << "角     : " << o << endl;
    cout << "分     : " << p << endl;


    return 0;
}