#include <iostream>
#include <string>
using namespace std;

void main() {
	string s;
	string m;
	string output;

	int i = 0;
	int k = 0;
	int count=1;

	cin >> s;
	cin >> m;
	//check string size
	while (s[i] != NULL) {
		i++;
	}
	while (m[k] != NULL) {
		k++;
	}
	//check overlapped
	for (int l = 0; l < i; l++) {
		for (int h = l+1; h < i; h++) {
			if (s[l] == s[h]) {
				count++;
			}
		}
		for (int h = 0; h < k; h++) {
			if (s[l] == m[h]) {
				count++;
			}
		}
		cout << s[l];
		if (count != 1) {
			cout << count;
		}
		count = 1;
	}
	for (int l = 0; l < k; l++) {
		for (int h = l + 1; h < k; h++) {
			if (m[k] == m[h]) {
				count++;
			}
		}
		cout << s[l];
		if (count != 1) {
			cout << count;
		}
		count = 1;

	}
}