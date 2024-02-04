#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	Employee(char* name, int age, char* country, char* job) //»ý¼ºÀÚ
		:age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->country = new char[strlen(country) + 1];
		strcpy(this->country, country);

		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);
	}
	bool isNameCorrect(char* name);
	void print();
	void change(char* name, int age, char* country, char* job);
};

Employee* member[10];
int mNum = 0;

int insert(char* name, int age, char* country, char* job)
{
	member[mNum] = new Employee(name,age,country,job);
	mNum++;
}

int main(void)
{

	while (1)
	{
		char choice[100];
		char name[100];
		int age;
		char country[100];
		char job[100];

		scanf("%s %s %d %s %s", choice, name,&age,country,job);

		if (strcpy(choice, "insert") == 0)
		{
			insert(name,age,country,job);
			break;
		}
		else if (strcpy(choice, "find") == 0)
		{

		}
		else if (strcpy(choice, "change") == 0)
		{

		}
		else if (strcpy(choice, "print") == 0)
		{

		}
		else if (strcpy(choice, "exit") == 0)
		{

		}
	}
}