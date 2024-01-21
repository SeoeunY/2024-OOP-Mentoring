#include <iostream>
using namespace std;

void merge_sort(int st, int en);
void merge(int st, int en);

int a[100000];
int tmp[100000];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(0, n);

    for (int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    return 0;
}

void merge_sort(int st, int en)
{
    if (en == (st + 1)) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

void merge(int st, int en)
{
    int mid = (st + en) / 2;
    int idx1 = st;
    int idx2 = mid;
    for (int i = st; i < en; i++) {
        if (idx2 == en) tmp[i] = a[idx1++];
        else if (idx1 == mid) tmp[i] = a[idx2++];
        else if (a[idx1] <= a[idx2]) tmp[i] = a[idx1++];
        else tmp[i] = a[idx2++];
    }
    for (int i = st; i < en; i++)
        a[i] = tmp[i];
}