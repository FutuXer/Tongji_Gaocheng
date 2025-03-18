//2353726 信01 付煜超
#include <iostream>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	int code = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
    int dn = 0, xn = 0, sn = 0, qn = 0;
    int sum = dn + xn + sn + qn;
	cin >> code >> daxie >> xiaoxie >> shuzi >> qita;
    if (cin.good() == 0)
    {
        cin.clear();
        cin.ignore(1024, '\n');
        return 0;
    }
    if (code < 12 || code>16)
    {
        cout << "密码长度[" << code << "]不正确";
        return 0;
    }
    if (daxie < 2 || daxie>code)
    {
        cout << "大写字母个数[" << daxie << "]不正确";
        return 0;
    }
    if (xiaoxie < 2 || xiaoxie>code)
    {
        cout << "小写字母个数[" << xiaoxie << "]不正确";
        return 0;
    }
    if (shuzi < 2 || shuzi>code)
    {
        cout << "数字个数[" << shuzi << "]不正确";
        return 0;
    }
    if (qita < 2 || qita>code)
    {
        cout << "其他符号个数[" << qita << "]不正确";
        return 0;
    }
    if (daxie + xiaoxie + shuzi + qita > code)
    {
        cout << "所有字符类型之和[" << daxie << "+" << xiaoxie << "+" << shuzi << "+" << qita << "]大于总密码长度[" << code << "]" << endl;
    }
    cout << code << " " << daxie << " " << xiaoxie << " " << shuzi << " " << qita << endl;

    char password[17] = { 0 };
    int i = 0;
    char ch = 0;
    for (int l = 0; l < 10;)
    {
        i = 0;
        ch = 0;
        dn = 0;
        xn = 0;
        sn = 0;
        qn = 0;
        while (i < code)
        {          
            int k1 = rand() % (4);
            if (k1 == 0)
            {
                ch = rand() % (26) + 'A';
                password[i] = ch;
                dn++;
            }
            if (k1 == 1)
            {
                ch = rand() % (26) + 'a';
                password[i] = ch;
                xn++;
            }
            if (k1 == 2)
            {
                ch = rand() % (10) + '0';
                password[i] = ch;
                sn++;
            }
            if (k1 == 3)
            {
                ch = other[rand() % (15)];
                password[i] = ch;
                qn++;
            }
            i++;               
        }
        if (dn < daxie || xn < xiaoxie || sn < shuzi || qn < qita)
        {
            continue;
        }
        for (int j = 0; j < code; j++)
        {
            cout << password[j];
        }
        cout << endl;
        l++;
    }

    return 0;
}