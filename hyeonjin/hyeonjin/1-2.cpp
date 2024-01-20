#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char input1[100] = { 0, };
	char input2[100] = { 0, };
	char input[200] = { 0, };
	char output[200] = { 0, };
	bool arr[200] = { false }; // Boolean array for duplicate checking
	int count = 0;

	cout << "First input : ";
	cin >> input1;
	cout << "Second input : ";
	cin >> input2;

	// Concatenate the two inputs into a single array
	strcat(input, input1);
	strcat(input, input2);
	// Put the first number into the output
	output[0] = input1[0];

	// Separate iteration for the first input
	for (int j = 0; j < strlen(input); j++) {
		if (input[0] == input[j]) {
			count++;
		}
		// Put the count of appearances into the output
		output[1] = count + '0';
	}
	// Iteration for the inputs starting from the second one
	for (int i = 1; i <= strlen(input); i++) {
		count = 0;

		// Check if the current number is the same as the previous one
		for (int k = 0; k < i; k++) {
			if (input[i] != input[k]) {
				arr[i] = true;
			}
			// Reset the array to false if a duplicate number is found
			else {
				arr[i] = false;
				break;
			}
		}
		// If there is no duplicate number
		if (arr[i]) {
			for (int j = 0; j < strlen(input); j++) {
				if (input[i] == input[j]) {
					count++;
				}
				// Put the next number into the output
				output[2 * i] = input[i];
				// Put the count of appearances into the output
				output[2 * i + 1] = count + '0';
			}
		}
		// If it is a duplicate number, initialize that part of the output to '0'
		else {
			output[2 * i] = '0';
			output[2 * i + 1] = count + '0';
		}
	}
	cout << "Output : ";
	// Exclude '0's and print the output
	for (int i = 0; i < strlen(output); i++) {
		if (output[i] != '0')
			cout << output[i];
	}
	return 0;
}