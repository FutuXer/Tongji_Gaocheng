//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;
    double a;
    double b;
    cout << "请输入半径和高度" << endl;
    cin >> a >> b ;
    cout << std::fixed << std::setprecision(2) << "圆周长        : " << 2 * a * pi << endl;
    cout << std::fixed << std::setprecision(2) << "圆面积        : " << pi * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "圆球表面积    : " << 4 * pi * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "圆球体积      : " << (static_cast<double>(4) / 3) * pi * a * a * a << endl;
    cout << std::fixed << std::setprecision(2) << "圆柱体积      : " << pi * a * a * b << endl;


    return 0;
}
















