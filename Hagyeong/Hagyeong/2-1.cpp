/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	int size; 
	cout<<"size: ";
	cin >> size; //Provide number of inputs to the program
	int tmp;

	int* arr=new int[size]; //Allocate memory for the number of inputs

	for (int k = 0;k < size;k++)
	{
		cin >> arr[k]; //Enter numbers to be sorted in ascending order
	}

	for (int k = 0;k < size-1;k++) //Sort with bubble sorting
	{
		for (int i = k+1;i < size;i++)
		{
			if (arr[k] > arr[i])
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