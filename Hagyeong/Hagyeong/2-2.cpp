/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int size;
	cout << "size: ";
	cin >> size; //Provide number of inputs to the program
	int tmp;
	int med;

	int* arr = new int[size]; //Allocate memory for the number of inputs

	for (int k = 0;k < size;k++)
	{
		cin >> arr[k]; //Enter numbers to be sorted in ascending order
	}

	for (int k = 1;k < size;k++) //Sort with Insertion sort
	{
		for (int i = 0;i < k;i++)
		{
			if (arr[k] < arr[i])
			{
				tmp = arr[k];
				arr[k] = arr[i];
				arr[i] = tmp;
			}
		}
	}

	med = (size - 1) / 2; //Find the median
	
	cout << "Ascending results : ";

	for (int k = 0;k < size;k++) //Print results in ascending order
	{
		cout << arr[k] << ' ';
	}

	cout << "\nthe median number : "; //Print median value
	cout << arr[med]<<endl;
}
*/
