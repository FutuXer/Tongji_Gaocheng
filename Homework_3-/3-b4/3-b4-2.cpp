//2353726 信01 付煜超
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;
    int a, b, c; 
    cout << "请输入三角形的两边及其夹角（角度）" << endl;
    cin >> a >> b >> c;
    float x;
    x = c * pi / 180;
    cout << "三角形的面积为 : " << std::fixed << std::setprecision(3) << float(0.5 * a * b * sin(x)) << endl;
    cout << sin(c) << endl;



    return 0;
}