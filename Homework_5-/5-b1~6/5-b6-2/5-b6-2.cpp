/* 2353726 信01 付煜超 */
#include <iostream>
#include <iomanip>
using namespace std;

int abc[3] = { 0,0,0 };                                    //记录圆盘个数//
int ABC[3][10] = { {0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0,0} };                //记录圆盘数//
int step = 1;                                            //计数全局变量/ push(char src, int n)                                                   //入栈函数//

void push(char src, int n)
{
    if (src == 'A') {
        ABC[0][abc[0]++] = n;
    }
    else if (src == 'B') {
        ABC[1][abc[1]++] = n;
    }
    else if (src == 'C') {
        ABC[2][abc[2]++] = n;
    }
}

int pop(char src)                                                          //出栈函数//
{
    int ini = 0;
    if (src == 'A') {
        ini = ABC[0][--abc[0]];
        return ini;
    }
    else if (src == 'B') {
        ini = ABC[1][--abc[1]];
        return ini;
    }
    else {
        ini = ABC[2][--abc[2]];
        return ini;
    }
}

void output(int step, int n, char src, char dst)
{
    cout << "第" << std::right << setw(4) << step << " 步" << "(" << std::right << setw(2) << n << "):" << std::right << setw(2) << src << "-->" << dst;
    cout << " A:";
    for (int i = 0; i < abc[0]; i++)
    {
        cout << std::right << setw(2) << ABC[0][i];
    }
    for (int space = 0; space < (21 - 2 * abc[0]); space++)
    {
        cout<<" ";
    }
    cout << " B:";
    for (int j = 0; j < abc[1]; j++) {
        cout << std::right << setw(2) << ABC[1][j];
    }
    for (int space = 0; space < (21 - 2 * abc[1]); space++)
    {
        cout << " ";
    }
    cout << " C:";
    for (int k = 0; k < abc[2]; k++)
    {
        cout << std::right << setw(2) << ABC[2][k];
    }
    cout << endl;
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
    int n;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
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
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (k != 65 && k != 66 && k != 67 && k != 97 && k != 98 && k != 99)
        {
            cin.clear();
            cin.ignore(1024, '\n');
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
            cin.clear();
            cin.ignore(1024, '\n');
        }
        while (1)
        {
            cout << "请输入目标柱(A-C)" << endl;
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
            if (cin.good() == 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l != 65 && l != 66 && l != 67 && l != 97 && l != 98 && l != 99)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            if (l == k)
            {
                cout << "目标柱(" << char(l) << ")不能与起始柱(" << char(k) << ")相同" << endl;
                cin.clear();
                cin.ignore(1024, '\n');
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
                        ABC[0][i] = n - i;
                    }
                    abc[0] = n;
                }
                else if (k == 'B')
                {
                    for (int i = 0; i < n; i++)
                    {
                        ABC[1][i] = n - i;
                    }
                    abc[1] = n;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        ABC[2][i] = n - i;
                    }
                    abc[2] = n;
                }
                cout << "初始:               ";
                cout << " A:";
                for (int i = 0; i < abc[0]; i++)
                {
                    cout << std::right << setw(2) << ABC[0][i];
                }
                for (int space = 0; space < (21 - 2 * abc[0]); space++)
                {
                    cout << " ";
                }
                cout << " B:";
                for (int j = 0; j < abc[1]; j++) {
                    cout << std::right << setw(2) << ABC[1][j];
                }
                for (int space = 0; space < (21 - 2 * abc[1]); space++)
                {
                    cout << " ";
                }
                cout << " C:";
                for (int k = 0; k < abc[2]; k++)
                {
                    cout << std::right << setw(2) << ABC[2][k];
                }
                cout << endl;
                hanoi(n, k, m, l);
                break;
            }
        }
        break;
    }


    return 0;
}