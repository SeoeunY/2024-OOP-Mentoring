#include <iostream>
#include <algorithm>

using namespace std;

int a[100000]; // input arr

void quick_sort(int st, int en); // func declare

int main(void)
{
	int n; // the number of inputs in advance.
	cin >> n;
	for (int i = 0; i < n; i++) // number input loop
		cin >> a[i];

	quick_sort(0, n);		// sort func call
	cout << a[(n - 1) / 2]; // output print
	return 0;
}

void quick_sort(int st, int en)
{
	if (en <= st + 1) // base condition
		return;

	int pivot = a[st]; // pivot reset
	int id1 = st + 1;  // index reset
	int id2 = en - 1;  // index reset

	while (1)
	{
		while (id1 <= id2 && a[id1] <= pivot)
			id1++; // index move
		while (id1 <= id2 && a[id2] > pivot)
			id2--; // index move
		if (id1 > id2)
			break;			  // loop break if
		swap(a[id1], a[id2]); // swap afte value compare
	}
	swap(a[st], a[id2]);	 // pivot and smaller than pivot value swap
	quick_sort(st, id2);	 // recursive call
	quick_sort(id2 + 1, en); // recursive call
}