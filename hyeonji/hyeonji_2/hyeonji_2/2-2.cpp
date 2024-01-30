#include <iostream>
using namespace std;

int main() {
	int size;
	cin >> size;

	int* arr = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < size; i++) { 
		for (int j = 0; j < i; j++) { //compare with until index of 'i'
			if (arr[i] < arr[j]) { 
				int tmp = arr[i]; 
				for (int k = i; k > j; k--) { //shift one space
					arr[k] = arr[k - 1];
				}
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		cout << arr[i]<<' ';
	}
}

