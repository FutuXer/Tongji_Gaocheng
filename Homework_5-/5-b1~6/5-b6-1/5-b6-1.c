/* 2353726 信01 付煜超 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int step = 1;                            //计数全局变量//
int a0;
int b0;
int c0;                                 //记录圆盘个数// 
int A[10] = { 0,0,0,0,0,0,0,0,0,0 };
int B[10] = { 0,0,0,0,0,0,0,0,0,0 };
int C[10] = { 0,0,0,0,0,0,0,0,0,0 };     //三个柱子//


void push(char src, int n)              //入栈函数//
{
    if (src == 'A')
    {
        A[a0++] = n;
    }
    else if (src == 'B')
    {
        B[b0++] = n;
    }
    else if (src == 'C')
    {
        C[c0++] = n;
    }
}

int pop(char src)                      //出栈函数//
{
    int ini = 0;
    if (src == 'A')
    {
        ini = A[--a0];
        return ini;
    }
    else if (src == 'B') 
    {
        ini = B[--b0];
        return ini;
    }
    else
    {
        ini = C[--c0];
        return ini;
    }
}

void output(int step, int n, char src, char dst)
{
    printf("第%4d 步(%2d):%2c-->%c", step, n, src, dst);
    printf(" A:");
    for (int i = 0; i < a0; i++)
    {
        printf("%2d", A[i]);
    }
    for (int space = 0; space < (21 - 2 * a0); space++)
    {
        printf(" ");
    }
    printf("B:");
    for (int j = 0; j < b0; j++) {
        printf("%2d", B[j]);
    }
    for (int space = 0; space < (21 - 2 * b0); space++)
    {
        printf(" ");
    }
    printf("C:");
    for (int k = 0; k < c0; k++) {
        printf("%2d", C[k]);
    }
    printf("\n");
}

void movedisk(char src, char dst, int n)
{
    int disk = pop(src);
    push(dst, disk);
    output(step, n, src, dst);
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        movedisk(src, dst, n);
        step = step++;
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n, ret;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
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
                int m;
                if (k != 65 && l != 65 && k != 97 && l != 97)
                    m = 65;
                if (k != 66 && l != 66 && k != 98 && l != 98)
                    m = 66;
                if (k != 67 && l != 67 && k != 99 && l != 99)
                    m = 67;
                if (k == 'A') 
                {
                    for (int i = 0; i < n; i++)
                    {
                        A[i] = n - i;
                    }
                    a0 = n;
                }
                else if (k == 'B')
                {
                    for (int i = 0; i < n; i++) 
                    {
                        B[i] = n - i;
                    }
                    b0 = n;
                }
                else 
                {
                    for (int i = 0; i < n; i++)
                    {
                        C[i] = n - i;
                    }
                    c0 = n;
                }
                printf("初始:               ");
                printf(" A:");
                for (int i = 0; i < a0; i++)
                {
                    printf("%2d", A[i]);
                }
                for (int space = 0; space < (21 - 2 * a0); space++)
                {
                    printf(" ");
                }
                printf("B:");
                for (int j = 0; j < b0; j++) {
                    printf("%2d", B[j]);
                }
                for (int space = 0; space < (21 - 2 * b0); space++)
                {
                    printf(" ");
                }

                printf("C:");
                for (int k = 0; k < c0; k++) {
                    printf("%2d", C[k]);
                }
                printf("\n");
                hanoi(n, k, m, l);
                break;
            }
        }
        break;
    }


    return 0;
}