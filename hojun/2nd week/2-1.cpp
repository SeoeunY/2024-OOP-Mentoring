#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;//the number of inputs in advance.
    int* a = new int[n];//Memory Allocation
    int i, j;
    for (int i = 0; i < n; i++)//number input loop
        cin >> *(a + i);

    i = 0, j = 0;//index reset
    int tmp, flag;//temp val && opti val
    while (i != n)
    {
        flag = 0;//reset
        j = 0;//reset
        while (j != n - i - 1)//linear swap loop
        {
            if (*(a + j) > *(a + j + 1))//swap if
            {
                tmp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = tmp;
                flag++;
            }
            j++;
        }
        if (flag == 0)//otimization
            break;
        i++;//plus for n(1st input) count
    }
    cout << *(a + ((n - 1) / 2));//output print
    delete[] a;//Clear Memory Allocation
    return 0;
}