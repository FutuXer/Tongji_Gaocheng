/* 2353726 付煜超 信01 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
int tj_strlen(const char* str)
{
    int i = 0;
    if (str == NULL)
    {
        return 0;
    }
    else
    {
        while (*str != '\0')
        {
            str++;
            i++;
        }
        return i;
    }
}

char *tj_strcat(char *s1, const char *s2)
{
    if (s2 == NULL || s1 == NULL)
    {
        return s1;
    }
    char* original_s1 = s1;
    while (*s1 != '\0')
    {
        s1++;
    }
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return original_s1;
}

char *tj_strncat(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int lens2 = tj_strlen(s2);
    int l = 0;
    int copy_len = (lens2 < len) ? lens2 : len;
    if (s1 == NULL || s2 == NULL)
    {
        return s1;
    }
    char* original_s1 = s1;
    while (*p != '\0')
    {
        p++;
    }
    while (*s2 != '\0' && l < copy_len) 
    {
        *p = *s2;
        p++;
        s2++;
        l++;
    }
    *p = '\0'; // 添加字符串结束符

    return original_s1;
}

char *tj_strcpy(char *s1, const char *s2)
{
    if (s1 == NULL)
    {
        return s1;
    }
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    char* original_s1 = s1;
    // 将s2的内容复制到s1
    while (*s2 != '\0') 
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0'; // 添加字符串结束符
    return original_s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p = s1;
    int lens2 = tj_strlen(s2);
    int l = 0;
    int copy_len = (lens2 < len) ? lens2 : len;

    if (s1 == NULL || s2 == NULL) 
    {
        return s1;
    }
    char* original_s1 = s1;
    while (copy_len >= 1)
    {
        *s1++ = *s2++;
        copy_len--;
    }

    return original_s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (1)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            return (int)*s1 - (int)*s2;
        }
        s1++;
        s2++;
    }

    return 0;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (1)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            char x = *s1, y = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                x = *s1 + 32;
            if (*s2 >= 'A' && *s2 <= 'Z')
                y = *s2 + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
        s1++;
        s2++;
    }

    return 0;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 1;
    int l = len;
    if (lens1 >= lens2)
    {
        lens1 = lens2;
        if (l > lens2)
        {
            l = lens2 + 1;
        }
    }
    if (len > lens1)
    {
        l = lens1 + 1;
    }
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;
    while (a <= l)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            return (int)*s1 - (int)*s2;
        }
        s1++;
        s2++;
        a++;
    }
    return 0;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    int lens1 = tj_strlen(s1);
    int lens2 = tj_strlen(s2);
    int a = 1;
    int l = len;
    if (lens1 >= lens2)
    {
        lens1 = lens2;
        if (l > lens2)
        {
            l = lens2 + 1;
        }
    }
    if (len > lens1)
    {
        l = lens1 + 1;
    }
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s2 == NULL && s1 != NULL)
        return 1;
    if (s1 == NULL && s2 == NULL)
        return 0;

    while (a <= l)
    {
        if (*s1 == '\0' && *s2 == '\0')
        {
            break;
        }
        if (*s1 != *s2)
        {
            char x = *s1, y = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                x = *s1 + 32;
            if (*s2 >= 'A' && *s2 <= 'Z')
                y = *s2 + 32;
            if (x != y)
            {
                return int(x - y);
            }
        }
        s1++;
        s2++;
        a++;
    }
    return 0;
}

char *tj_strupr(char *str)
{
    char* p = str;
    if (str == NULL) 
    {
        return str;
    }
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 32;
        }
        str++;
    }

    return p;
}

char *tj_strlwr(char *str)
{
    char* p = str;
    if (str == NULL)
    {
        return str;
    }
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str + 32;
        }
        str++;
    }

    return p;
}

int tj_strchr(const char *str, const char ch)
{
    if (str == NULL)
    {
        return 0;
    }
    int loc = 1;
    while (*str != '\0')
    {
        if (*str == ch)
        {
            return loc;
        }
        str++;
        loc++;
    }

    return 0;
}

int tj_strstr(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int lensub = tj_strlen(substr);
    int loc = 1;
    while (*str != '\0')
    {
        const char* p_str = str;
        const char* p_substr = substr;
        // 检查是否匹配子字符串
        while (*p_substr != '\0' && *p_str == *p_substr)
        {
            p_str++;
            p_substr++;
        }
        // 如果子字符串到达了末尾，说明匹配成功
        if (*p_substr == '\0')
        {
            // 计算匹配的起始位置
            return loc;
        }
        str++;
        loc++;
    }

    return 0;
}

int tj_strrchr(const char *str, const char ch)
{
    if (str == NULL)
    {
        return 0;
    }
    int len = tj_strlen(str);
    while (*str != '\0')
    {
        str++;
    }
    str--;
    while (len >= 0)
    {
        if (*str == ch)
        {
            return len;
        }
        len--;
        str--;
    }
    return 0;
}

int tj_strrstr(const char *str, const char *substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    int len = tj_strlen(str);
    int lensub = tj_strlen(substr);
    while (*str != '\0')
    {
        str++;
    }
    str--;
    while (*substr != '\0')
    {
        substr++;
    }
    substr--;
    while (len > 0)
    {
        if (*str == *substr)
        {
            int i = 0;
            while (*str == *substr)
            {
                i++;
                str--;
                substr--;
                lensub--;
                len--;
            }

            if (lensub == 0)
            {
                return len + 1;
            }
            else
            {
                str = str + i - 1;
                substr = substr + i;
                len = len + i - 1;
                lensub = lensub + i;
            }
        }
        else
        {
            str--;
            len--;
        }
    }

    return 0;
}

char *tj_strrev(char *str)
{
    if (str == NULL)
        return str;

    char* p = str;
    char* p_str = str;

    while (*p_str != '\0') // 找到字符串的末尾
    {
        p_str++;
    }
    p_str--; // 将指针移到字符串末尾的前一个位置

    while (p < p_str) // 交换字符，直到两个指针相遇
    {
        char temp = *p;
        *p = *p_str;
        *p_str = temp;

        p++;
        p_str--;
    }

    return str;
}
