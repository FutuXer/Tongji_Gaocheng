/* 2353726 信01 付煜超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a = 1;
/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int a = 1;
    if (n == 0)
    {
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("%5d:%3d#%2c-->%c\n", a, n, src, dst);
        a = a++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n, ret;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret = scanf("%d", &n);
        if (ret == 0)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (n < 1 || n>16)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        else
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            break;
        }
    }
    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        int k = getchar();
        if (k == 'a') {
            k = 'A';
        }
        if (k == 'b') {
            k = 'B';
        }
        if (k == 'c') {
            k = 'C';
        }
        if (ret == 0)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        else
        {
            if (k == 65 || k == 97)
                k = 65;

            if (k == 66 || k == 98)
                k = 66;

            if (k == 67 || k == 99)
                k = 67;
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
        while (1)
        {
            printf("请输入目标柱(A-C)\n");
            int l = getchar();
            if (l == 'a') {
                l = 'A';
            }
            if (l == 'b') {
                l = 'B';
            }
            if (l == 'c') {
                l = 'C';
            }
            if (ret == 0)
            {
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            
            if (l == k)
            {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", l, k);
                char ch;
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            else
            {
                if (l == 65 || l == 97)
                    l = 65;

                if (l == 66 || l == 98)
                    l = 66;

                if (l == 67 || l == 99)
                    l = 67;
                printf("移动步骤为:\n");
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                hanoi(n, k, m, l);
                break;
            }
        }
        break;
    }


    return 0;
}