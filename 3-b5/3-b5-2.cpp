//2353726 信01 付煜超
#include <iostream>
using namespace std;

int main()
{
    int year, month, day, a;
    cout << "请输入年，月，日" << endl;
    cin >> year >> month >> day;
   
        if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))
        {
            if (month < 1 || month>12)
            {
                cout << "输入错误-月份不正确" << endl;
            }
            else
            {
                switch (month)
                {
                    case 1:
                        a = day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 2:
                        a = 31 + day;
                        if (day < 1 || day>29)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 3:
                        a = 60 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 4:
                        a = 91 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 5:
                        a = 121 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 6:
                        a = 152 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 7:
                        a = 182 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 8:
                        a = 213 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 9:
                        a = 244 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 10:
                        a = 274 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 11:
                        a = 305 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 12:
                        a = 335 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                }
            }
        }
        else
        {
            if (month < 1 || month>12)
            {
                cout << "输入错误-月份不正确" << endl;
            }
            else
            {
                switch (month)
                {
                    case 1:
                        a = day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 2:
                        a = 31 + day;
                        if (day < 1 || day>28)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 3:
                        a = 59 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 4:
                        a = 90 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 5:
                        a = 120 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 6:
                        a = 151 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 7:
                        a = 181 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 8:
                        a = 212 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 9:
                        a = 243 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 10:
                        a = 273 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 11:
                        a = 304 + day;
                        if (day < 1 || day>30)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    case 12:
                        a = 334 + day;
                        if (day < 1 || day>31)
                        {
                            cout << "输入错误-日与月的关系非法" << endl;
                        }
                        else
                            cout << year << "-" << month << "-" << day << "是" << year << "年的第" << a << "天" << endl;
                        break;
                    
                }
            }


                
                
            
        }
   



    return 0;
}
