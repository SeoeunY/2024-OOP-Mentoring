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
	void print() const;
	void change(char* name, int age, char* country, char* job);
	~Employee()//Destructor
	{
		//free memory part//
		delete[] this->name;
		delete[] this->country;
		delete[] this->job;
	}
};



int main()
{
	Employee* emp[10];//employee array
	for (int i = 0; i < 10; i++)
		emp[i] = NULL;
	int emp_num = 0;//employee number
	char input[10] = {};//command input array
	char fi[20];//find command input array
	///input information variable
	char name[20];
	int age;
	char country[20];
	char job[20];
	//////////////////

	while (1)
	{
		cin >> input;//command input

		if (strcmp(input, "exit") == 0) { break; }//break point
		else if (strcmp(input, "print") == 0)
		{
			cout << "=====print=====\n";
			for (int i = 0; i < emp_num; i++)
				emp[i]->print();
		}
		else if (strcmp(input, "insert") == 0)
		{
			cin >> name >> age >> country >> job;//Enter employee information
			emp[emp_num] = new Employee(name, age, country, job);//employee memory allocation
			emp_num++;//employee increase
		}
		else if (strcmp(input, "find") == 0)
		{
			cin >> fi;//Enter the name you want to find
			for (int i = 0; i < emp_num; i++)
			{
				if (emp[i]->isNameCorrect(fi))//name correct if
				{
					cout << "=====find=====\n";
					emp[i]->print();
				}
			}
		}
		else if (strcmp(input, "change") == 0)
		{
			cin >> input >> name >> age >> country >> job;//Enter information to replace
			for (int i = 0; i < emp_num; i++)//employee search loop
			{
				if (emp[i]->isNameCorrect(input))//name correct if
				{
					emp[i]->change(name, age, country, job);//change function
					break;
				}
			}
		}
	}
	for (int i = 0; i < emp_num; i++)
		delete emp[i];
}

//////class member function define part/////////
Employee::Employee(char* name, int age, char* country, char* job)
{
	int len = strlen(name);//input array's length
	this->name = new char[len + 1];//memory allocation
	strcpy(this->name, name);//input array copy
	len = strlen(country);//input array's length
	this->country = new char[len + 1];//memory allocation
	strcpy(this->country, country);//input array copy
	len = strlen(job);//input array's length
	this->job = new char[len + 1];//memory allocation
	strcpy(this->job, job);//input array copy
	this->age = age;
}

bool Employee::isNameCorrect(char* name) const
{
	return !strcmp(this->name, name);//Use not, because it's 1 if it's the same
}

void Employee::print() const
{
	/////////////print part////////////
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Country: " << this->country << endl;
	cout << "Job: " << this->job << endl;
	cout << "----------\n";
}

void Employee::change(char* name, int age, char* country, char* job)
{
	//free existing allocation///
	delete[] this->name;
	delete[] this->country;
	delete[] this->job;
	////////////////////////////
	int len = strlen(name);//input array's length
	this->name = new char[len + 1];//memory allocation
	strcpy(this->name, name);//input array copy
	len = strlen(country);//input array's length
	this->country = new char[len + 1];//memory allocation
	strcpy(this->country, country);//input array copy
	len = strlen(job);//input array's length
	this->job = new char[len + 1];//memory allocation
	strcpy(this->job, job);//input array copy
	this->age = age;
}