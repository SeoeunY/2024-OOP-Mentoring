#include <iostream>
using namespace std;

char arr[3072][6144];
int N;

void star(int x, int y) {
    arr[x + 0][y + 2] = '*';

    arr[x + 1][y + 1] = '*';
    arr[x + 1][y + 3] = '*';

    arr[x + 2][y + 0] = '*';
    arr[x + 2][y + 1] = '*';
    arr[x + 2][y + 2] = '*';
    arr[x + 2][y + 3] = '*';
    arr[x + 2][y + 4] = '*';

}

void recursion(int n, int x, int y) {
    if (n == 3) {
        star(x, y);
        return;
    }
    recursion(n / 2, x, y + n / 2);
    recursion(n / 2, x + n / 2, y);
    recursion(n / 2, x + n / 2, y + n);

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2; j++) {
            arr[i][j] = ' ';
        }
    }
    recursion(N, 0, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return;
}