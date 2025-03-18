//2353726 信01 付煜超
#include <iostream>
using namespace std;

int main()
{
	char a[3][128] = { 0 };
	int daxie = 0;
	int xiaoxie = 0;
	int shuzi = 0;
	int kongge = 0;
	int qita = 0;
	cout << "请输入第1行" << endl;
	cin.getline(a[0], 128, '\n');
	cout << "请输入第2行" << endl;
	cin.getline(a[1], 128, '\n');
	cout << "请输入第3行" << endl;
	cin.getline(a[2], 128, '\n');
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 127; j++)
		{
			if (a[i][j] == 0)
				break;
			if (a[i][j] >= 'A' && a[i][j] <= 'Z')
				daxie++;
			else if (a[i][j] >= 'a' && a[i][j] <= 'z')
				xiaoxie++;
			else if (a[i][j] >= '0' && a[i][j] <= '9')
				shuzi++;
			else if (a[i][j] == ' ')
				kongge++;
			else if (a[i][j] != '\0')
				qita++;
		}
	}
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << shuzi << endl;
	cout << "空格 : " << kongge << endl;
	cout << "其它 : " << qita << endl;

	return 0;
}