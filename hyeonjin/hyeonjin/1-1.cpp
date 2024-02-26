#include <iostream>
#include <cstring> // memset
using namespace std;

char star[3072][6144]; // Vertical size N, Horizontal size 2N-1

void print_star(int x, int y, int n) {
	// Base case : print the basic unit of stars
	if (n == 3) {
		star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
	}
	// Recursive calls
	else { 
		print_star(x, y, n / 2);
		print_star(x + n / 2, y - n / 2, n / 2);
		print_star(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	int N;
	cin >> N;

	// Initialize the star array with spaces
	memset(star, ' ', sizeof(star));

	// Call the function to print the star pattern
	print_star(0, N - 1, N); 

	// Double loop to output the star array
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}