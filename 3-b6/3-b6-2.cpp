//2353726 ĞÅ01 ¸¶ìÏ³¬
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    double a;
    cin >> a;
    double x = a + 1e-6;
    int b = (int)(x / 10);
    double c = x / 10 - b;
    int d = b / 1000000000;
    int e = b / 100000000 - 10 * d;
    int f = b / 10000000 - 10 * e - 100 * d;
    int g = b / 1000000 - 1000 * d - 100 * e - 10 * f;
    int h = b / 100000 - 10000 * d - 1000 * e - 100 * f - 10 * g;
    int i = b / 10000 - 100000 * d - 10000 * e - 1000 * f - 100 * g - 10 * h;
    int j = b / 1000 - 1000000 * d - 100000 * e - 10000 * f - 1000 * g - 100 * h - 10 * i;
    int k = b / 100 - 10000000 * d - 1000000 * e - 100000 * f - 10000 * g - 1000 * h - 100 * i - 10 * j;
    int l = b / 10 - 100000000 * d - 10000000 * e - 1000000 * f - 100000 * g - 10000 * h - 1000 * i - 100 * j - 10 * k;
    int m = b / 1 - 1000000000 * d - 100000000 * e - 10000000 * f - 1000000 * g - 100000 * h - 10000 * i - 1000 * j - 100 * k - 10 * l;
    int n = int(10 * c);
    int o = int(100 * c) - 10 * n;
    int p = int(1000 * c) - 100 * n - 10 * o;

    cout << "´óĞ´½á¹ûÊÇ:" << endl;
    //Ê®ÒÚºÍÒÚÎ»
    switch (e)
    {
        case 0:
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (e > 0)
        cout << "Ê°";
    switch (f)
    {
        case 0:
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (f > 0)
        cout << "ÒÚ";
    else if (e>0&&f==0)
    {
        cout << "ÒÚ";
    }
 //Ç§Íòµ½ÍòÎ»
    switch (g)
    {
        case 0:
            if (f+h+i+j+k+l+m+n==0||f+h+i+j==0||h+i+j==0)
            {
            }
            else if (e+f==0)
            {
            }
            else
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (g > 0)
        cout << "Çª";
    switch (h)
    {
        case 0:
            if (g == 0)
            {
            }
            else if (i == 0 && j == 0)
            {
            }
            else
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;          
    }
    if (h > 0)
        cout << "°Û";
    switch (i)
    {
        case 0:
            if (h == 0)
            {
            }
            else if (j == 0)
            {
            }
            else
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;           
    }
    if (i > 0)
        cout << "Ê°";
    switch (j)
    {
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (g>0||h>0||i>0||j>0)
    {
        cout << "Íò";
    }
    //Ç§µ½¸ö
    switch (k)
    {
        case 0:
            if (a>9999.99&&l+m+n>0)
            {
                cout << "Áã";
            }
            else if (a>9999.99&&l+m+n==0)
            {
            }
            else
            {
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;          
    }
    if (k > 0)
        cout << "Çª";
    switch (l)
    {
        case 0:
            if (k == 0)
            {
            }
            else if (m == 0 && n == 0)
            {
            }
            else
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (l > 0)
        cout << "°Û";
    switch (m)
    {
        case 0:
            if (l == 0)
            {
            }
            else if (n == 0)
            {
            }
            else
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (m > 0)
        cout << "Ê°";
    switch (n)
    {
        case 0:
            if (e+f+g+h+i+j+k+l+m==0&&o+p==0)
            {
                cout << "Áã";
            }
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 2:
            cout << "·¡";
            break;
        case 3:
            cout << "Èş";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 5:
            cout << "Îé";
            break;
        case 6:
            cout << "Â½";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 9:
            cout << "¾Á";
            break;
    }
    if (e+f+g+h+i+j+k+l+m+n==0&&o+p>0)
    {
    }
    else
    {
        cout << "Ô²";
    }
    if (o==0&&p==0)
    {
        cout << "Õû" << endl;
    }
    else if (o>0&&p==0)
    {
        switch (o)
        {
            case 1:
                cout << "Ò¼";
                break;
            case 2:
                cout << "·¡";
                break;
            case 3:
                cout << "Èş";
                break;
            case 4:
                cout << "ËÁ";
                break;
            case 5:
                cout << "Îé";
                break;
            case 6:
                cout << "Â½";
                break;
            case 7:
                cout << "Æâ";
                break;
            case 8:
                cout << "°Æ";
                break;
            case 9:
                cout << "¾Á";
                break;
        }
        cout << "½Ç" << "Õû" << endl;
    }
    else
    {
        switch (o)
        {
            case 0:
                if (e+f+g+h+i+j+k+l+m+n>0&&p>0)
                {
                    cout << "Áã";
                }
                else
                {
                }
                break;
            case 1:
                cout << "Ò¼";
                break;
            case 2:
                cout << "·¡";
                break;
            case 3:
                cout << "Èş";
                break;
            case 4:
                cout << "ËÁ";
                break;
            case 5:
                cout << "Îé";
                break;
            case 6:
                cout << "Â½";
                break;
            case 7:
                cout << "Æâ";
                break;
            case 8:
                cout << "°Æ";
                break;
            case 9:
                cout << "¾Á";
                break;
        }
        if (o>0)
        {
            cout << "½Ç";
        }
        switch (p)
        {
            case 0:
                break;
            case 1:
                cout << "Ò¼";
                break;
            case 2:
                cout << "·¡";
                break;
            case 3:
                cout << "Èş";
                break;
            case 4:
                cout << "ËÁ";
                break;
            case 5:
                cout << "Îé";
                break;
            case 6:
                cout << "Â½";
                break;
            case 7:
                cout << "Æâ";
                break;
            case 8:
                cout << "°Æ";
                break;
            case 9:
                cout << "¾Á";
                break;
        }
        if (p > 0)
        {
            cout << "·Ö" << endl;
        }
    }
    return 0;
}