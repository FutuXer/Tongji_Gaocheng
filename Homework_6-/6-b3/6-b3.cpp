/* 2353726 付煜超 信01 */
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	char str[32] = { 0 }, * p, * pe;
	p = str;
	pe = str;
	int power = 0;
	int sum = 0;

	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;

	while (*pe != '\0')
	{
		pe++;
	}
	power = pe - str - 1;
	for (p = str; p <= pe - 1; p++)
	{
		if (*p == '1')
		{
			sum = sum + (unsigned int)pow(2, power);
		}
		power--;
	}

	cout << sum << endl;
}