//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int leapjudge(int year,int month,int day)
{
    int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int c[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 4 == 0) && (year % 400 == 0))//是闰年
    {
        if (day > b[month] || day < 1)
        {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (day > c[month] || day < 1)
        {
            printf("输入错误-日与月的关系非法\n");
            return 0;
        }
        else
        {
            return 2;
        }
    }
}

int daycal(int month, int day, int judge)
{
    if (judge == 1)
    {
        int sum = 0;
        int a[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < month; i++)
        {
            sum = sum + a[i];
        }
        sum = sum + day;
        return sum;
    }
    else
    {
        int sum = 0;
        int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        for (int i = 0; i < month; i++)
        {
            sum = sum + a[i];
        }
        sum = sum + day;
        return sum;
    }
}

int main()
{
    int year, month, day, a;
    printf("请输入年，月，日\n");
    scanf("%d %d %d", &year, &month, &day);

    if (month > 12 || month < 1) 
    {
        printf("输入错误-月份不正确\n");
        return 0;
    }
    else 
    {
        int judge = leapjudge(year, month, day);
        a = daycal(month, day, judge);
    }
    printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, a);


    return 0;
}