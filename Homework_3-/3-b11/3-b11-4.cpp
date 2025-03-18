//2353726 ÐÅ01 ¸¶ìÏ³¬
#include <iostream> 
using namespace std;

int main()
{
	int i, j, k, sum = 0;

	 i = 0;
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				cout << "*";
				sum++;
				if (k == 2)
				{
					continue;
				}
				if (k == 3)
				{
					break;
				}
				/************/
			}
			cout << ' ';
			if (j == 3)
			{
				break;
			}
			/************/
		}
		cout << endl;
		/************/

	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}