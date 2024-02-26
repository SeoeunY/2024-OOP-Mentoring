#include <iostream>
using namespace std;

//quickSort code
void quickSort(int* arr, int left, int right) {
	int pivot = (left + right) / 2; //set pivot

	int i = left;
	int j = right;

	while (i <= j) {
		while (arr[i] < arr[pivot]) {
			i++;
		}
		while (arr[j] > arr[pivot]) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j) { //left side recursion
		quickSort(arr, left, j);
	}
	if (i < right) { //right side recursion
		quickSort(arr, i, right);
	}
}

int main() {
	int size;
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, size - 1);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}

