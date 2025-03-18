//2353726 信01 付煜超
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int year, month, day, a, leap;
    while (1)
    {
        cout << "请输入年份(2000-2030)和月份(1-12) : " ;
        cin >> year >> month;
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
            leap = 1;
        else
            leap = 0;
        if (cin.good() == 0)
        {
            cout << "输入非法，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (year < 2000 || year>2030 || month < 1 || month>12)
        {
            cout << "输入非法，请重新输入" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        while (1)
        {
            cout << "请输入" << year << "年" << month << "月" << "1日的星期(0-6表示星期日-星期六) : ";
            cin >> day;
            if (cin.good() == 0)
            {
                cout << "输入非法，请重新输入" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (day < 0 || day>6)
            {
                cout << "输入非法，请重新输入" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            break;
        }
        cout << endl;
        cout << year << "年" << month << "月的月历为:" << endl;
        cout << "星期日  " << "星期一  " << "星期二  " << "星期三  " << "星期四  " << "星期五  " << "星期六" << endl;
        if (month==1|| month == 3 || month == 5||month == 7|| month == 8|| month == 10|| month == 12)
        {
            a = 31;
        }
        else if ( month == 4 || month == 6 || month == 9 || month == 11 )
        {
            a = 30;
        }
        else 
        {
            a = 28 + leap;
        }
        for (int i = 1; i <= a; i++)
        {
            if (i==1)
            {
                for (int j = 0; j < day; j++)
                {
                    cout << "        ";
                }
            }
            cout << setw(4) << std::right << i << "    ";
            if ((i+day)%7==0)
            {
                cout << endl;
            }
        }
        break;
    }
    return 0;
}
