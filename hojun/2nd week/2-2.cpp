#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;//the number of inputs in advance.
    int* a = new int[n];//Memory Allocation
    int i, j, tmp, t;//index val && temp val
    for (i = 0; i < n; i++)//number input loop
        cin >> *(a + i);

    for (i = 0; i < n; i++)
    {
        t = i;//reset
        for (j = i + 1; j < n; j++)//linear swap loop
        {
            if (*(a + t) > *(a + j))//swap if
                t = j;
        }
        if (t != i)//Works only in situations to swap
        {
            tmp = *(a + i);
            *(a + i) = *(a + t);
            *(a + t) = tmp;
        }
    }

    cout << *(a + ((n - 1) / 2));//output print

    delete[] a;//Clear Memory Allocation
    return 0;
}