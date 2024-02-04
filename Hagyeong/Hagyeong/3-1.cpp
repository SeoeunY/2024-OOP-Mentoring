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
	Employee(char* name, int age, char* country, char* job)
		:age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->country = new char[strlen(country) + 1];
		strcpy(this->country, country);

		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);
	}

	//bool isNameCorrect(char* name)
	
	char* comparename()
	{

		return this->name;
	}

	void print(void) const
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		cout << "Country: " << this->country << endl;
		cout << "Job: " << this->job << endl;
	}

	void change(char* name, int age, char* country, char* job)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->country = new char[strlen(country) + 1];
		strcpy(this->country, country);

		this->job = new char[strlen(job) + 1];
		strcpy(this->job, job);

		this->age = age;
	}
};

Employee* member[10];
int mNum = 0;

void insert(char* name, int age, char* country, char* job)
{
	member[mNum] = new Employee(name,age,country,job);
	mNum++;
}

void printFind(int i)
{
	cout << "=====find=====" << endl;
	member[i]->print();
	cout << "----------"<<endl;
}

void find(char* name)
{
	for (int i = 0;i < mNum;i++)
	{
		if (member[i]->comparename() == name)
		{
			printFind(i);
			break;
		}
		else if(member[i]->comparename() != name && (i == mNum - 1))
			break;
	}
}

void printAll(void)
{
	cout << "=====print=====" << endl;
	for (int k = 0;k < mNum;k++)
	{
		member[k]->print();
		cout << "----------" << endl;
	}
}

void changeFind(char *name, char* name2, int age, char* country, char* job)
{
	for (int i = 0;i < mNum;i++)
	{
		if (member[i]->comparename() == name)
		{
			member[i]->change(name2,age,country,job);
			break;
		}
		else if (member[i]->comparename() != name && (i == mNum - 1))
			break;
	}
}

int main(void)
{

	while (1)
	{
		char choice[100];
		char name[100];
		char name2[100];
		int age;
		char country[100];
		char job[100];

		scanf("%s", choice);

		if (strcmp(choice, "insert") == 0)
		{
			scanf("%s %d %s %s",name, &age, country, job);
			insert(name,age,country,job);
		}
		else if (strcmp(choice, "find") == 0)
		{
			scanf("%s", name);
			find(name);
		}
		else if (strcmp(choice, "change") == 0)
		{
			scanf("%s %s %d %s %s", name, name2, &age, country, job);
			changeFind(name,name2,age,country,job);
		}
		else if (strcmp(choice, "print") == 0)
		{
			printAll();
		}
		else if (strcmp(choice, "exit") == 0)
		{
			break;
		}
	}
	return 0;
}