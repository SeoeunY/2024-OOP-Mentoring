#include <iostream>
using namespace std;

int sorted[10];

void merge(int* arr, int m, int mid, int n) {
	int i = m;
	int j = mid + 1;
	int k = m;
	
	while (i <= mid && j <= n) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > mid) {
		for (int t = j; t <= n; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		arr[t] = sorted[t];
	}
}

void mergeSort(int* arr,int m,int n) {
	if (m < n) {
		int mid = (m + n) / 2;
		mergeSort(arr, m, mid);
		mergeSort(arr, mid + 1, n);
		merge(arr, m, mid, n);
	}
}

int main() {
	int size;
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
}
