//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "请输入一个[1..30000]间的整数:" << endl;
    int a;
    cin >> a;
    int b = a / 10000;
    int c = a / 1000 - 10 * b;
    int d = a / 100 - 10 * c - 100 * b;
    int e = a / 10 - 1000 * b - 100 * c - 10 * d;
    int f = a - 10000 * b - 1000 * c - 100 * d - 10 * e;
    cout << "万位 : " << b << endl;
    cout << "千位 : " << c << endl;
    cout << "百位 : " << d << endl;
    cout << "十位 : " << e << endl;
    cout << "个位 : " << f << endl;

    return 0;
}