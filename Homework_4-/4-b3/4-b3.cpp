//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
    int year = y % 100;
    int c = int(y / 100);
    int w = year + int(year / 4) + int(c / 4) - 2 * c + int(26 * (m + 1) / 10) + d - 1;
    while (w < 0)
    {
        w = w + 7;
    }
    int xingqi = w % 7;
    return xingqi;
}

int main()
{
    int y, month, d = 1, leap, t = 0;
    while (1)
    {
        cout << "请输入年[1900-2100]、月" << endl;   
        cin >> y >> month;
        cout << endl;
        cout << y << "年" << month << "月" << endl;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            cout << "输入错误，请重新输入" << endl;
            continue;
        }
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
            cout << "输入非法，请重新输入" << endl;
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
    cout << "======================================================" << endl;
    cout << "星期日  " << "星期一  " << "星期二  " << "星期三  " << "星期四  " << "星期五  " << "星期六" << endl;
    cout << "======================================================" << endl;
    for (int i = 1; i <= t; i++)
    {
        if (i == 1)
        {
            for (int j = 0; j < zeller(y,m,d); j++)
            {
                cout << "        ";
            }
        }
        cout << setw(4) << std::right << i << "    ";
        if ((i + zeller(y, m, d)) % 7 == 0)
        {
            cout << endl;
        }
        if (i == t)
        {
            cout << endl;
        }
    }
    cout << "======================================================" << endl;
    return 0;
}