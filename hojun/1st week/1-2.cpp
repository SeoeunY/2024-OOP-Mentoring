#include <iostream>
#include <cstring> //==>string.h
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char first[10] = {};
    char second[100] = {};
    cout << "first input: ";
    cin >> first;
    cout << "second input: ";
    cin >> second;
    int len1 = strlen(first);
    int len2 = strlen(second);
    int t, k, flag;//

    /////////////print of the first input//////////
    for (int i = 0; i < len1; i++)
    {
        t = first[i] - '0';
        flag = 1;
        for (int j = 0; j < len2; j++)
        {
            k = second[j] - '0';
            if (t == k)
            {
                second[j] = 'a';
                flag++;
            }
        }
        cout << t << flag;
    }
    /////////////////////////////////////////////

    //print of the rest part of the second input//
    for (int i = 0; i < len2; i++)
    {
        if (second[i] != 'a')
        {
            t = second[i] - '0';
            flag = 1;
            for (int j = i + 1; j < len2; j++)
            {
                k = second[j] - '0';
                if (t == k)
                {
                    second[j] = 'a';
                    flag++;
                }
            }
            cout << t << flag;
        }
    }
    ////////////////////////////////////////////////
    return 0;
}