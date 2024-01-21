#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
char space[10000][10000];

void func(int n, int f, int b)
{
    if (n == 3) //Print stars like the example when the input number is 3
    {
        space[f][b] = '*';  //First line
        space[f + 1][b - 1] = '*'; //second line
        space[f + 1][b + 1] = '*';
        for (int i = b - 2; i <= b + 2; ++i) //Third line
        {
            space[f + 2][i] = '*';
        }
        return;
    }

    if (n > 3) //If the entered number is greater than 3
    {
        int m = n / 2;
        func(m, f, b); //Repeating the process of printing stars with different parameters using a recursive function.
        func(m, f + m, b - m);
        func(m, f + m, b + m);
    }
}

int main(void)
{
    int n;

    cin >> n; //Receive input from the user.

    func(n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (space[i][j] == '*') //If the value in the array is '*', print '*'
                cout << '*';
            else
                cout << ' '; //If the value in the array is ' ', print ' '

        }
        cout << endl; //line break
    }

}