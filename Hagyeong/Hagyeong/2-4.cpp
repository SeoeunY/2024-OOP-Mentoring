/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void merge(int arr[], int tmp[], int start, int mid, int end)
{
	for (int i = start;i < end+1;i++) 
	{
		tmp[i] = arr[i]; //Add arr array value to tmp array
	}

	int ob = start; //one block (Front array of divided arrays)
	int tb = mid + 1; //two block (Rear array of divided arrays)
	int num = start; //Set num to determine how much the array is aligned

	while (ob <= mid && tb <= end) //If the array is not used up
	{
		if (tmp[ob] <= tmp[tb]) //If the value of the front array is small
		{
			arr[num] = tmp[ob];
			ob++;
		}
		else //If the value of the rear array is small
		{
			arr[num] = tmp[tb];
			tb++;
		}
		num++;
	}

	for (int i = 0;i < num - ob;i++) //If the front array is not used up and the iteration is finished(The rear arrangement is already aligned, so this process is not necessary)
	{
		arr[num + i] = tmp[ob + i];
	}
}

void merge1(int arr[], int tmp[], int start, int end)
{
	if (start < end) //Recursive function call condition
	{
		int mid = (start + end) / 2; //Obtaining the median value
		merge1(arr, tmp, start, mid);//Divide forward array by median
		merge1(arr, tmp, mid + 1, end);//Divide back array by median
		merge(arr, tmp, start, mid, end);//merge
	}
}

int main(void)
{
	int size;
	cout << "size: ";
	cin >> size; //Provide number of inputs to the program
	int med;
	med = (size - 1) / 2; //Find the median

	int* arr = new int[size]; //Allocate memory for the number of inputs
	int* tmp = new int[size];

	for (int k = 0;k < size;k++)
	{
		cin >> arr[k]; //Enter numbers to be sorted in ascending order
	}

	merge1(arr,tmp,0,size-1); //function call

	cout << "Ascending results : ";

	for (int k = 0;k < size;k++) //Print results in ascending order
	{
		cout << arr[k] << ' ';
	}

	cout << "\nthe median number : "; //Print median value
	cout << arr[med] << endl;
}
*/