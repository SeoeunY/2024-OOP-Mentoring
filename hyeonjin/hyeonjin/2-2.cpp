#include <iostream>
using namespace std;

int main(void) {
	int size;
	int i = 0;
	int j = 0;
	int key;
	// Get the number of inputs
	cout << "Number of inputs : ";
	cin >> size;

	int* arr = new int[size]; // Dynamic  memory allocation

	// Get integers
	cout << "Input integers with spaces : ";
	for (i = 0; i < size; i++) {
		cin >> arr[i];
	}

	//  Insertion sort
	for (int i = 1; i < size; i++) {
		key = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = key;
	}
	// Print the median number
	cout << "Median number : " << arr[i / 2] << endl;

	delete[] arr; // Deallocate memory
	return 0;
}