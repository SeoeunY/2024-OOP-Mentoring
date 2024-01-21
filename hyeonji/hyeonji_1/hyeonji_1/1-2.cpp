#include <iostream>
#include <string>
using namespace std;

void main() {
    bool arr[20];
    char s[20];
    char m[20];
    int s_cou = 0;
    int m_cou = 0;
    int count = 1;
    int i = 0;
    int j = 0;

    for (int i = 0; i < 20; i++) {
        arr[i] = false;
    }

    cin >> s;
    cin >> m;

    while (s[i] != NULL) {
        s_cou++;
        i++;
    }

    while (m[j] != NULL) {
        m_cou++;
        j++;
    }

    for (int i = 0; i < s_cou; i++) {
        for (int j = 0; j < m_cou; j++) {
            if (s[i] == m[j]) {
                count++;
                arr[j] = true;
            }
        }
        cout << s[i] << count;
        count = 1;

    }
    for (int i = 0; i < m_cou-1; i++) {
        for (int j = i+1; j < m_cou; j++) {
            if (m[i] == m[j] && arr[i] == false) {
                count++;
                arr[j] = true;
            }
        }
        if (arr[i] != true) {
            cout << m[i] << count;
        }
        count = 1;

    }
}