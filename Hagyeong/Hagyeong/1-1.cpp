#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
char space[10000][10000];

void func(int n, int f, int b)
{
    if (n == 3)
    {
        space[f][b] = '*';
        space[f + 1][b - 1] = '*';
        space[f + 1][b + 1] = '*';
        for (int i = b - 2; i <= b + 2; ++i)
        {
            space[f + 2][i] = '*';
        }
        return;
    }

    if (n > 3)
    {
        int m = n / 2;
        func(m, f, b);
        func(m, f + m, b - m);
        func(m, f + m, b + m);
    }
}

int main(void)
{
    int n;

    cout << "원하는 줄의 수를 입력하시오 :";
    cin >> n;

    func(n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (space[i][j] == '*')
                cout << '*';
            else
                cout << ' ';

        }
        cout << endl;
    }

}