//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
    int year = y %100;
    int c = int(y / 100);
    int w = year + int(year / 4) + int(c / 4) - 2 * c + int(26 * (m + 1) / 10) + d -1;
    while (w<0)
    {
            w = w + 7;
    }
    int xingqi = w % 7;
    switch (xingqi)
    {
        case 0:
            cout << "星期日" << endl;
            break;
        case 1:
            cout << "星期一" << endl;
            break;
        case 2:
            cout << "星期二" << endl;
            break;
        case 3:
            cout << "星期三" << endl;
            break;
        case 4:
            cout << "星期四" << endl;
            break;
        case 5:
            cout << "星期五" << endl;
            break;
        case 6:
            cout << "星期六" << endl;
            break;
        default:
            break;
    }
    return 0;
}

int main()
{
    int y, month, d, leap, t = 0;
    while (1)
    {
        cout << "请输入年[1900-2100]、月、日：" << endl;
        cin >> y >> month >> d;
        if ((y % 4 == 0) && (y % 100 != 0) || (y % 4 == 0) && (y % 400 == 0))
            leap = 1;
        else
            leap = 0;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            t = 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11 || month == 10)
            t = 30;
        else 
            t = 28 + leap;
        if (cin.good() == 0)
        {
            cout << "输入错误，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (y < 1900 || y>2100)
        {
            cout << "年份不正确，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (month < 1 || month>12)
        {
            cout << "月份不正确，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else if (d < 1 || d>t)
        {
            cout << "日不正确，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    int m;
    if (month == 1)
    {
        m = 13;
        y = y - 1;
    }
    else if (month == 2)
    {
        m = 14;
        y = y - 1;
    }
    else
    {
        m = month;
    }
    zeller(y, m, d);
    return 0;
}