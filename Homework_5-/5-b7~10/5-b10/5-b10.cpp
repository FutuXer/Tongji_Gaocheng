/* 2353726 信01 付煜超 */
#include <iostream>
#include <iomanip>

using namespace std;

int cal1[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int cal2[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool x5, x6, x51, x52, x53, x61, x62, x63;


int leapyear(int year)//判断闰年
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;//是闰年
	else
		return 0;//不是闰年
}

int zeller(int y, int m, int d)
{
	int year = y % 100;
	int c = int(y / 100);
	int w = year + int(year / 4) + int(c / 4) - 2 * c + int(26 * (m + 1) / 10) + d - 1;
	while (w < 0)
	{
		w = w + 7;
	}
	int xingqi = w % 7;

	return xingqi;
}


void print_day(int year)
{
	int judge = leapyear(year);
	cout << "            1月                             2月                             3月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	int calendar[6][23] = { 0 };
	int ini1 = -zeller(year - 1, 13, 1) + 1;
	int ini2 = -zeller(year - 1, 14, 1) + 1;
	int ini3 = -zeller(year, 3, 1) + 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			calendar[i][j] = ini1;
			ini1++;
			if (ini1 > 31)
			{
				break;
			}
		}
		if (ini1 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 8; j < 15; j++)
		{
			calendar[i][j] = ini2;
			ini2++;
			if (judge == 1 && ini2 > 29)
			{
				break;
			}
			if (judge == 0 && ini2 > 28)
			{
				break;
			}
		}
		if (judge == 1 && ini2 > 29)
		{
			break;
		}
		if (judge == 0 && ini2 > 28)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			calendar[i][j] = ini3;
			ini3++;
			if (ini3 > 31)
			{
				break;
			}
		}
		if (ini3 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar[4][i] > 0)
		{
			x5 = 1;
			break;
		}
		else if (calendar[4][22] <= 0)
		{
			x5 = 0;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar[5][i] > 0)
		{
			x6 = 1;
			break;
		}
		else if (calendar[5][22] <= 0)
		{
			x6 = 0;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (calendar[i][j] > 0 && i < 4)
			{
				cout << std::left << setw(4) << calendar[i][j];
			}
			else if (calendar[i][j] <= 0 && i < 4)
			{
				cout << "    ";
			}
			if (x5 == 1 && i == 4)
			{
				if (calendar[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar[i][j];
				}
				else if (calendar[i][j] <= 0)
					cout << "    ";
			}
			if (x6 == 1 && i == 5)
			{
				if (calendar[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar[i][j];
				}
				else if (calendar[i][j] <= 0)
					cout << "    ";
			}
		}
		if (i < 4)
			cout << endl;
		if (x5 == 1 && i == 4)
			cout << endl;
		if (x6 == 1 && i == 5)
			cout << endl;
	}
	cout << endl;
	int calendar1[6][23] = { 0 };
	cout << "            4月                             5月                             6月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	int ini4 = -zeller(year, 4, 1) + 1;
	int ini5 = -zeller(year, 5, 1) + 1;
	int ini6 = -zeller(year, 6, 1) + 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			calendar1[i][j] = ini4;
			ini4++;
			if (ini4 > 30)
			{
				break;
			}
		}
		if (ini4 > 30)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 8; j < 15; j++)
		{
			calendar1[i][j] = ini5;
			ini5++;
			if (ini5 > 31)
			{
				break;
			}
		}
		if (ini5 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			calendar1[i][j] = ini6;
			ini6++;
			if (ini6 > 30)
			{
				break;
			}
		}
		if (ini6 > 30)
		{
			break;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar1[4][i] > 0)
		{
			x51 = 1;
			break;
		}
		else if (calendar1[4][22] <= 0)
		{
			x51 = 0;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar1[5][i] > 0)
		{
			x61 = 1;
			break;
		}
		else if (calendar1[5][22] <= 0)
		{
			x61 = 0;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (calendar1[i][j] > 0 && i < 4)
			{
				cout << std::left << setw(4) << calendar1[i][j];
			}
			else if (calendar1[i][j] <= 0 && i < 4)
			{
				cout << "    ";
			}
			if (x51 == 1 && i == 4)
			{
				if (calendar1[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar1[i][j];
				}
				else if (calendar1[i][j] <= 0)
					cout << "    ";
			}
			if (x61 == 1 && i == 5)
			{
				if (calendar1[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar1[i][j];
				}
				else if (calendar1[i][j] <= 0)
					cout << "    ";
			}
		}
		if (i < 4)
			cout << endl;
		if (x51 == 1 && i == 4)
			cout << endl;
		if (x61 == 1 && i == 5)
			cout << endl;
	}
	cout << endl;
	int calendar2[6][23] = { 0 };
	cout << "            7月                             8月                             9月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	int ini7 = -zeller(year, 7, 1) + 1;
	int ini8 = -zeller(year, 8, 1) + 1;
	int ini9 = -zeller(year, 9, 1) + 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			calendar2[i][j] = ini7;
			ini7++;
			if (ini7 > 31)
			{
				break;
			}
		}
		if (ini7 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 8; j < 15; j++)
		{
			calendar2[i][j] = ini8;
			ini8++;
			if (ini8 > 31)
			{
				break;
			}
		}
		if (ini8 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			calendar2[i][j] = ini9;
			ini9++;
			if (ini9 > 30)
			{
				break;
			}
		}
		if (ini9 > 30)
		{
			break;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar2[4][i] > 0)
		{
			x52 = 1;
			break;
		}
		else if (calendar2[4][22] <= 0)
		{
			x52 = 0;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar2[5][i] > 0)
		{
			x62 = 1;
			break;
		}
		else if (calendar2[5][22] <= 0)
		{
			x62 = 0;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (calendar2[i][j] > 0 && i < 4)
			{
				cout << std::left << setw(4) << calendar2[i][j];
			}
			else if (calendar2[i][j] <= 0 && i < 4)
			{
				cout << "    ";
			}
			if (x52 == 1 && i == 4)
			{
				if (calendar2[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar2[i][j];
				}
				else if (calendar2[i][j] <= 0)
					cout << "    ";
			}
			if (x62 == 1 && i == 5)
			{
				if (calendar2[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar2[i][j];
				}
				else if (calendar2[i][j] <= 0)
					cout << "    ";
			}
		}
		if (i < 4)
			cout << endl;
		if (x52 == 1 && i == 4)
			cout << endl;
		if (x62 == 1 && i == 5)
			cout << endl;
	}
	cout << endl;
	int calendar3[6][23] = { 0 };
	cout << "           10月                            11月                            12月" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	int ini10 = -zeller(year, 10, 1) + 1;
	int ini11 = -zeller(year, 11, 1) + 1;
	int ini12 = -zeller(year, 12, 1) + 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			calendar3[i][j] = ini10;
			ini10++;
			if (ini10 > 31)
			{
				break;
			}
		}
		if (ini10 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 8; j < 15; j++)
		{
			calendar3[i][j] = ini11;
			ini11++;
			if (ini11 > 30)
			{
				break;
			}
		}
		if (ini11 > 30)
		{
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 16; j < 23; j++)
		{
			calendar3[i][j] = ini12;
			ini12++;
			if (ini12 > 31)
			{
				break;
			}
		}
		if (ini12 > 31)
		{
			break;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar3[4][i] > 0)
		{
			x53 = 1;
			break;
		}
		else if (calendar3[4][22] <= 0)
		{
			x53 = 0;
		}
	}
	for (int i = 0; i < 23; i++)
	{
		if (calendar3[5][i] > 0)
		{
			x63 = 1;
			break;
		}
		else if (calendar3[5][22] <= 0)
		{
			x63 = 0;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if (calendar3[i][j] > 0 && i < 4)
			{
				cout << std::left << setw(4) << calendar3[i][j];
			}
			else if (calendar3[i][j] <= 0 && i < 4)
			{
				cout << "    ";
			}
			if (x53 == 1 && i == 4)
			{
				if (calendar3[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar3[i][j];
				}
				else if (calendar3[i][j] <= 0)
					cout << "    ";
			}
			if (x63 == 1 && i == 5)
			{
				if (calendar3[i][j] > 0)
				{
					cout << std::left << setw(4) << calendar3[i][j];
				}
				else if (calendar3[i][j] <= 0)
					cout << "    ";
			}
		}
		if (i < 4)
			cout << endl;
		if (x5 == 1 && i == 4)
			cout << endl;
		if (x6 == 1 && i == 5)
			cout << endl;
	}
	cout << endl;
}



int main()
{
	int year;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.good() == 0) 
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (year < 1900 || year>2100)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else {
			break;
		}
	}
	
	print_day(year);
	cout << endl;


	return 0;



}



/*int ROW[12] = { 0 };
	for (int i = 0; i < 12; i++)
	{
		ROW[i] = cal_row(year, month);
	}
	int row1, row2, row3, row4;
	int row11 = (ROW[0] > ROW[1] ? ROW[0] : ROW[1]);
	row1 = (row11 > ROW[2] ? row11 : ROW[2]);
	int row21 = (ROW[3] > ROW[4] ? ROW[3] : ROW[4]);
	row2 = (row21 > ROW[5] ? row21 : ROW[5]);
	int row31 = (ROW[6] > ROW[7] ? ROW[6] : ROW[7]);
	row3 = (row31 > ROW[8] ? row31 : ROW[8]);
	int row41 = (ROW[9] > ROW[10] ? ROW[9] : ROW[10]);
	row4 = (row41 > ROW[11] ? row41 : ROW[11]);
	int ini1 = month_ini(year, 1, 1);
	int ini2 = month_ini(year, 2, 1) + 8;
	int ini3 = month_ini(year, 3, 1);
	for (int i = 0; i < 7; i++)
	{
		if (i < ini1)
			cout << "    ";
		else
			cout << std::left << setw(4) << i + 1 - ini1;
	}
	for (int j = 7; j < 15; j++)
	{
		if (j < ini2)
			cout << "    ";
		else
			cout << std::left << setw(4) << j + 1 - ini2;
	}

*/