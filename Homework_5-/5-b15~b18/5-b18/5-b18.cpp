//2353726 ÐÅ01 ¸¶ìÏ³¬
#include <iostream>
#include <ctime>
using namespace std;

static const char other[] = "!@#$%^&*-_=+,.?";

int tj_strlen(const char str[])
{
    int i = 1;
    if (str[0] == '\0')
        return 0;
    else
    {
        while (str[i] != '\0')
        {
            i++;
        }
        return i;
    }
}

int main()
{
    char a = 0;
    cin >> a;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    int code = 0, daxie = 0, xiaoxie = 0, shuzi = 0, qita = 0;
    cin >> code >> daxie >> xiaoxie >> shuzi >> qita;
    int dn = 0, xn = 0, sn = 0, qn = 0;
    int sum = dn + xn + sn + qn;
    char password[11][256] = { 0 };
    for (int i = 0; i < 11; i++)
    {
        cin.getline(password[i], 256, '\n');
    }
    for (int i = 1; i < 11; i++)
    {
        int len = tj_strlen(password[i]);
        if (len != code)
        {
            cout << "´íÎó" << endl;
            return 0;
        }
    }
    for (int i = 1; i < 11; i++)
    {
        dn = 0;
        xn = 0;
        sn = 0;
        qn = 0;
        sum = 0;
        for (int j = 0; j < code; j++)
        {
            if (password[i][j] >= 'A' && password[i][j] <= 'Z')
            {
                dn++;
            }
            if (password[i][j] >= 'a' && password[i][j] <= 'z')
            {
                xn++;
            }
            if (password[i][j] >= '0' && password[i][j] <= '9')
            {
                sn++;
            }
            for (int k = 0; k < 15; k++)
            {
                if (password[i][j] == other[k])
                {
                    qn++;
                }
            }         
        }
        sum = dn + xn + sn + qn;
        if (dn < daxie || xn < xiaoxie || sn < shuzi || qn < qita || sum != code)
        {
            cout << "´íÎó" << endl;
            return 0;
        }
    }
    
    cout << "ÕýÈ·" << endl;

    return 0;
}