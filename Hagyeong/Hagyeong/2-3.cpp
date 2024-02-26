#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void qicksort(int arr[], int start, int end)
{
	if (start >= end)
		return;

	int pivot=start; //pivot settings
	int r = start + 1; //Variables to move to the right (This variable will find a small value)
	int l = end; //Variables to move to the left (This variable will find a big value)
	int temp;

	while (r <= l)
	{
		while (arr[r] <= arr[pivot]) //Until you meet a value greater than pivot
			r++;
		while (arr[l] >= arr[pivot] && l > start)//Until you meet a value less than pivot
			l--;
		if (r > l)
		{
			temp = arr[l];
			arr[l] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}

	}

	qicksort(arr, start, l - 1); //Perform a recursive function for forward alignment of pivot criteria
	qicksort(arr, l + 1, end); //Perform a recursive function for backward alignment of pivot criteria
}

int main(void)
{
	int size;
	cout << "size: ";
	cin >> size; //Provide number of inputs to the program
	int med;
	med = (size - 1) / 2; //Find the median
	int num = 0;
	int* arr = new int[size]; //Allocate memory for the number of inputs
	int* tmp = new int[size];

	for (int k = 0;k < size;k++)
	{
		cin >> arr[k]; //Enter numbers to be sorted in ascending order
	}

	qicksort(arr, 0, size - 1);

	cout << "Ascending results : ";

	for (int k = 0;k < size;k++) //Print results in ascending order
	{
		cout << arr[k] << ' ';
	}

	cout << "\nthe median number : "; //Print median value
	cout << arr[med] << endl;
}