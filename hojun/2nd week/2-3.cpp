#include <iostream>
using namespace std;

//////func declare
void merge_sort(int st, int en);
void merge(int st, int en);

///input arr & temp arr
int a[100000];
int tmp[100000];

int main(void)
{
    int n;//the number of inputs in advance.
    cin >> n;

    for (int i = 0; i < n; i++)//number input loop
        cin >> a[i];

    merge_sort(0, n);//sort func call

    cout << a[(n - 1) / 2];//output print
    return 0;
}

void merge_sort(int st, int en)
{
    if (en == (st + 1)) return;//base condition
    int mid = (st + en) / 2;//mid reset
    merge_sort(st, mid);//recursive call
    merge_sort(mid, en);//recursive call
    merge(st, en);//merge func call
}

void merge(int st, int en)
{
    int mid = (st + en) / 2;//mid reset
    int idx1 = st;//start point reset
    int idx2 = mid;//end point reset
    for (int i = st; i < en; i++) {
        if (idx2 == en) tmp[i] = a[idx1++];//idx2 val end
        else if (idx1 == mid) tmp[i] = a[idx2++];//idx1 val end
        else if (a[idx1] <= a[idx2]) tmp[i] = a[idx1++];//value compare
        else tmp[i] = a[idx2++]; //value compare
    }
    for (int i = st; i < en; i++)//move to std arr from the temp arr
        a[i] = tmp[i];
}