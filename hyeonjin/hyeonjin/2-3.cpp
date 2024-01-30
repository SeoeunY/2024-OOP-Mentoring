#include <iostream>
using namespace std;

// Function to swap two integers
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int * arr, int start, int end) {
	if (start >= end)
		return;

	int left = start;
	int right = end;
	int pivot = (start + end) / 2; // Choose the pivot as the median

	// Partition the array such that elements smaller than pivot are on the left,
	// and elements greater than pivot are on the right
	while (left < right) {
		while (arr[left] < arr[pivot])
			left++;
		while (arr[right] > arr[pivot])
			right--;

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}

	// Recursively sort the subarrays on the left and right of the pivot
	quickSort(arr, start, right);
	quickSort(arr, left, end);
}

int main(void) {
	int size;

	// Get the number of inputs
	cout << "Number of inputs : ";
	cin >> size;

	int* arr = new int[size]; // Dynamic  memory allocation

	// Get integers
	cout << "Input integers with spaces : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	// Perform quick sort on the input array
	quickSort(arr, 0, size-1);

	// Print the median number
	cout << "Median number : " << arr[i / 2] << endl;

	delete[] arr; // Deallocate memory
	return 0;
}