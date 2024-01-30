#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee//class declare
{
private:
	char* name;
	int age = 0;
	char* country;
	char* job;
public:
	Employee(char* name, int age, char* country, char* job);
	bool isNameCorrect(char* name) const;
	void print();
	void change(char* name, int age, char* country, char* job);
};

Employee* emp[10];

int main()
{
	int emp_num = 0;//employee number
	char input[10] = {};//command input array

	///input information variable
	char name[20];
	int age;
	char country[20];
	char job[20];
	//////////////////

	while (1)
	{
		cin >> input;

		if (strcmp(input, "exit") == 0) { break; }
		else if (strcmp(input, "print") == 0)
		{
			for (int i = 0; i < emp_num; i++)
				emp[i]->print();
		}
		else if (strcmp(input, "insert") == 0)
		{
			cin >> name >> age >> country >> job;
			emp[emp_num++] = new Employee(name, age, country, job);
		}
		else if (strcmp(input, "find") == 0)
		{
			cin >> input;
			for (int i = 0; i < emp_num; i++)
			{
				if (emp[i]->isNameCorrect(input))
					emp[i]->print();
			}
		}
		else if (strcmp(input, "change") == 0)
		{

		}

	}
}

//////class member function define part/////////
Employee::Employee(char* name, int age, char* country, char* job)
{
	this->name = name;
	this->age = age;
	this->country = country;
	this->job = job;
}

bool Employee::isNameCorrect(char* name) const
{
	if (strcmp(this->name, name) == 0)
		return true;
	else
		return false;
}

void Employee::print()
{
	cout << "=====print=====\n";
	for (int i = 0; i < 10; i++)
	{
		if (emp[i]->age != 0)
		{
			cout << "Name: " << emp[i]->name;
			cout << "Age: " << emp[i]->age;
			cout << "Country: " << emp[i]->country;
			cout << "Job: " << emp[i]->job;
		}
		else
			break;
	}
}

void Employee::change(char* name, int age, char* country, char* job)
{
	return;
}