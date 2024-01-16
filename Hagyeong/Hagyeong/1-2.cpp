
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
    char ip1[100], ip2[100];
    char imsi[200];

    cin >> ip1 >> ip2; //Receive input of 2 values from the user

    strcpy(imsi, ip1); //Save to an array
    strcat(imsi, ip2); // Merge two arrays

    int len = strlen(imsi); //Measure the length of an array

    for (int i = 0;i < len;i++)
    {
        if (i == len -1) //If it's the last number in the array (1) If it's that single number or 2) if it's a number for which the value has already been printed)
        {
            for (int k = 0;k < len - 1;k++)
            {
                if (imsi[len - 1] == imsi[k])
                    break; //If it's a number for which the value has already been printed, terminate the program
                else if ((imsi[len - 1] != imsi[k]) && (len - 1 == k + 1))
                {
                    cout << imsi[len - 1] << 1; //If it's a number that hasn't been printed yet, since it's the only one, print the number itself and 1 together.
                    break;
                }
                else
                    continue;
            }
        }
        else //Numbers up to the last one but one
        {
            int s = 1;
            int p = 1;

            for (;;)
            {
                if (imsi[i] == imsi[i + p]) //If there are identical numbers,
                {
                    s++; //Counting numbers
                    p++; //Moving the value being compared
                }
                else //If there are no identical numbers,
                    p++; //Moving the value being compared

                if ((p + i) == len) //When all comparisons are done and the count is determined (output condition)
                {
                    if (i > 0) //If it's not the first number (because there might be overlaps)
                    {
                        for (int k = 0;k < i;k++)
                        {
                            if (imsi[k] == imsi[i]) //Escape the loop since it's not necessary to output if there is an overlap.
                                break;
                            else if ((imsi[k] != imsi[i]) && ((k + 1) == i)) //If it completes without any overlaps until the end,
                            {
                                cout << imsi[i] << s; //Print your own number and its count.
                                break;
                            }
                        }
                        break;
                    }

                    else if (i == 0) //If it's the first number (no need for comparison)
                    {
                        cout << imsi[i] << s; //Print your own number and its count.
                        break;
                    }
                }
            }

        }
    }
}
