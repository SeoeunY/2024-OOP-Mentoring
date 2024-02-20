
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

	for (int k = 0;k < size;k++) //Sort with bubble sorting
	{
		for (int i = 0;i < size-1;i++)
		{
			if (arr[i] > arr[i+1])
			{
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
	}

	int med = (size - 1) / 2; //Find the median
	
	cout << "Ascending results : ";

	for (int k = 0;k < size;k++) //Print results in ascending order
	{
		cout << arr[k] << ' ';
	}

	cout << "\nthe median number : "; //Print median value
	cout << arr[med]<<endl;
}
