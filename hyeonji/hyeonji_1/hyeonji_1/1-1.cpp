#include <iostream>
using namespace std;

void main() {
	int N;
	cin >> N;
	for (int col = N-1; col >= 0; col--) {
		if (col % 3 == 2) {
			for (int i = 0; i < col; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < col; i++)
				cout << " ";
			cout << endl;
		}
		else if (col % 3 == 1) {
				for (int i = 0; i < col; i++)
					cout << " ";
				cout << "* *";
				for (int i = 0; i < col; i++)
					cout << " ";
				cout << endl;

		}
		else if (col % 3 == 0) {
				for (int i = 0; i < col; i++)
					cout << " ";
				cout << "*****";
				for (int i = 0; i < col; i++)
					cout << " ";
				cout << endl;

		}
		cout << endl;
	}


}