/* 2353726 付煜超 信01 */
#include <iostream>
using namespace std;

int fun1(char* str)
{
	int len = 0;
	char* p, * pe;
	pe = str;
	p = str;
	while (*pe != '\0')
	{
		pe++;
	}
	//结束后为带尾0的长度
	len = pe - str;
	pe = pe - 2;
	for (p = str; p <= str + len - 1; p++)
	{
		if (*p != *pe)
		{
			return 0;
			break;
		}
		if (pe == str)
		{
			break;
		}
		pe--;
	}
	return 1;
}

int main()
{
	char str[80] = { 0 };
	int x = 0;

	cout << "请输入一个长度小于80的字符串（回文串）" << endl;

	fgets(str, 80, stdin);
	x = fun1(str);
	
	if (x == 0)
	{
		cout << "no" << endl;
	}
	if (x == 1)
	{
		cout << "yes" << endl;
	}


	return 0;
}