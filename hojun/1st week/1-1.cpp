#include <iostream>
using namespace std;

char arr[3072][6144];
char tri[3][6] = { {"  *  "}, {" * * "}, {"*****"} };

void f(int n, int x, int y);//recursion function

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;//n is 3*(2^k) (k>=0 && k<=10)
	

	////2d array reset loop//////
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			arr[i][j] = ' ';
		}
	}
	////////////////////////////

	f(n, n - 1, 0);//recursion func call

	//////2d array print///////////////
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
			cout << arr[i][j];
		cout << "\n";
	}
	//////////////////////////////////
	return 0;
}

void f(int n, int x, int y)
{
	if (n <= 3)
	{
		for (int i = 0; i < 5; i++)
		{
			arr[y][x + i - 2] = tri[0][i];
			arr[y + 1][x + i - 2] = tri[1][i];
			arr[y + 2][x + i - 2] = tri[2][i];
		}
		return;
	}
	else if (n > 3)
	{
		f(n / 2, x - n / 2, y + n / 2);
		f(n / 2, x + n / 2, y + n / 2);
		f(n / 2, x, y);
	}
}