#include <iostream>
using namespace std;

void triangle(int column, int col);

void main() {
	int N;
	cin >> N;

	for (int col = N-1; col >= 0; col--) 
	{
		int column = col%3;
		triangle(column, col);
		cout << endl;
	}
}

void triangle(int column, int col) {
	switch (column)
	{
	case 2:
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << endl;
		break;

	case 1:
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << "* *";
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << endl;
		break;

	case 0:
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << "*****";
		for (int i = 0; i < col; i++)
			cout << " ";
		cout << endl;
		break;
	}

}