#include <iostream>
using namespace std;

// Function to merge two sorted halves of an array
void mergeSort(int* arr, int* sorted, int start, int end) {
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = start;

    // Merge the two halves into a sorted array
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    // Copy the remaining elements from the first half, if any
    while (i <= mid)
        sorted[k++] = arr[i++];
    // Copy the remaining elements from the second half, if any
    while (j <= end)
        sorted[k++] = arr[j++];

    // Copy the sorted elements back to the original array
    for (int i = start; i <= end; i++) {
        arr[i] = sorted[i];
    }
}

// Recursive function to partition
void partition(int* arr, int* sorted, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        partition(arr, sorted, start, mid);
        partition(arr, sorted, mid + 1, end);
        mergeSort(arr, sorted, start, end);
    }
}

int main(void) {
	int size;

	// Get the number of inputs
	cout << "Number of inputs : ";
	cin >> size;

	// Dynamic  memory allocation
	int* arr = new int[size]; 
	int* sorted = new int[size];

	// Get integers
	cout << "Input integers with spaces : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	// Perform merge sort on the input array
    partition(arr, sorted, 0, size - 1);

	// Print the median number
	cout << "Median number : " << sorted[size / 2] << endl;

    // Deallocate memory
	delete[] arr; 
    delete[] sorted;
	return 0;
}