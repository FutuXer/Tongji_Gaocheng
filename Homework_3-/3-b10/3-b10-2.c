/* 班级 学号 姓名*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int x, y, z, n;
	//百位
	n = 1;
	for (int a1 = 1; a1 <= 5; a1++)
	{
		for (int a2 = a1 + 1; a2 <= 8; a2++)
		{
			for (int a3 = a2 + 1; a3 <= 9; a3++)
			{
				//个位
				for (int b1 = 1; b1 <= 9; b1++)
				{
					if (b1 == a1 || b1 == a2 || b1 == a3)
						continue;
					for (int b2 = 1; b2 <= 9; b2++)
					{
						if (b2 == a1 || b2 == a2 || b2 == a3 || b2 == b1)
							continue;
						for (int b3 = 1; b3 <= 9; b3++)
						{
							if (b3 == a1 || b3 == a2 || b3 == a3 || b3 == b1 || b3 == b2)
								continue;
							for (int c1 = 1; c1 <= 9; c1++)
							{
								if (c1 == a1 || c1 == a2 || c1 == a3 || c1 == b1 || c1 == b2 || c1 == b3)
									continue;
								for (int c2 = 1; c2 <= 9; c2++)
								{
									if (c2 == a1 || c2 == a2 || c2 == a3 || c2 == b1 || c2 == b2 || c2 == b3 || c2 == c1)
										continue;
									for (int c3 = 1; c3 <= 9; c3++)
									{
										if (c3 == a1 || c3 == a2 || c3 == a3 || c3 == b1 || c3 == b2 || c3 == b3 || c3 == c1 || c3 == c2)
											continue;
										x = 100 * a1 + 10 * b1 + c1;
										y = 100 * a2 + 10 * b2 + c2;
										z = 100 * a3 + 10 * b3 + c3;
										if (x + y + z == 1953)
										{

											printf("No.%3d\t : %d+%d+%d=%d\n", n, x, y, z, x + y + z);
											n = n + 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}



	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}