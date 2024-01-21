#include <iostream>
using namespace std;

int main(void) {
	int size;
	int temp = 0;
	int i = 0;
	int j = 0;
	// Get the number of inputs
	cout << "Number of inputs : ";
	cin >> size;

	int* arr = new int[size]; // Dynamic  memory allocation

	// Get integers
	cout << "Input integers with spaces : ";
	for (i = 0; i < size; i++) {
	cin >> arr[i];
	}

	// Bubble sort
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// Print the median number
	cout << "Median number : "<< arr[i/2]<< endl;

	delete[] arr; // Deallocate memory
	return 0;
}