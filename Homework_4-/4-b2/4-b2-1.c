//2353726 信01 付煜超
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int zeller(int y, int m, int d) {
    int year = y % 100;
    int c = y / 100;
    int w = year + (year / 4) + (c / 4) - 2 * c + (26 * (m + 1) / 10) + d - 1;
    while (w < 0)
    {
        w = w + 7;
    }
    int xingqi = w % 7;
    switch (xingqi) 
    {
        case 0:
            printf("星期日\n");
            break;
        case 1:
            printf("星期一\n");
            break;
        case 2:
            printf("星期二\n");
            break;
        case 3:
            printf("星期三\n");
            break;
        case 4:
            printf("星期四\n");
            break;
        case 5:
            printf("星期五\n");
            break;
        case 6:
            printf("星期六\n");
            break;
        default:
            break;
    }
    return 0;
}

int main()
{
    int y, month, d, leap, t = 0, ret;
    while (1)   
    {
        printf("请输入年[1900-2100]、月、日：\n");
        scanf("%d %d %d", &y, &month, &d);
        ret = scanf("%d%d%d", &y, &month, &d);
        if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 400 == 0))
            leap = 1;
        else
            leap = 0;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            t = 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11 || month == 10)
            t = 30;
        else
            t = 28 + leap;
        if (ret == 0)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("输入错误，请重新输入\n");
            continue;
        }
        if (y < 1900 || y > 2100)
        {
            printf("年份不正确，请重新输入\n");
            continue;
        }
        else if (month < 1 || month > 12)
        {
            printf("月份不正确，请重新输入\n");
            continue;
        }
        else if (d < 1 || d > t) 
        {
            printf("日不正确，请重新输入\n");
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
