#include <iostream>
using namespace std;

int main() {
	int tmp;
	int size;
	cin >> size;

	int* arr = new int[size]; //dynamic memory allocation

	for (int i = 0; i < size; i++) { //input value 
		cin >> arr[i];
	}
	
	while (1) {
		int count = 0;
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] > arr[i + 1]) { //pass by value
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				count++;
			}
		}
		if (count == 0) //if do not need swap anymore, break
			break;
	}

	for (int i = 0; i < size; i++) { //output value of array
		cout << arr[i]<<' ';
	}
}