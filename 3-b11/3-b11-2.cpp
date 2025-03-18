//2353726 ÐÅ01 ¸¶ìÏ³¬
#include <iostream> 
using namespace std;

int main()
{
	int i, j, k, sum = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 4; k++) {
				cout << "*";
				sum++;
				if (k==2)
				{
					continue;
				}
				if (k==3)
				{
					break;
				}
				/************/
			}
			cout << ' ';
			if (j==1)
			{
				break;
			}
			/************/
		}
		cout << endl;
		/************/
	}

	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}