#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main(void)
{
	char ip1[100], ip2[100];
	char imsi[200];

	cout << "숫자 두 개를 입력하시오 : ";
	cin >> ip1 >> ip2;

	strcpy(imsi, ip1);
	strcat(imsi, ip2);

	int len = strlen(imsi);

	for (int i = 0;i < len-1;i++)
	{
		int s = 1;
		int p = 1;

		for (;;)
		{
			if (imsi[i] == imsi[i + p])
			{
				s++;
				p++;
			}
			else
				p++;

			if ((p + i) == len)
			{
				if (i > 0)
				{
					for (int k = 0;k < i;k++)
					{
						if (imsi[k] == imsi[i])
							break;
						else if ((imsi[k] != imsi[i]) && ((k + 1) == i))
						{
							cout << imsi[i] << s;
							break;
						}
					}
					break;
				}

				else if(i==0)
				{
					cout << imsi[i] << s;
					break;
				}
			}
		}
	}

	int su = 1;

	for (int k = 0;k < len-1;k++)
	{
		if (imsi[len - 1] == imsi[k])
			break;
		else if ((imsi[len - 1] != imsi[k]) && (len - 1 == k + 1))
		{
			cout << imsi[len-1] << su;
			break;
		}
		else
			continue;
	}
}