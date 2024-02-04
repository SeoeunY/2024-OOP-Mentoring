#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
	char* name;
	int age;
	char* class_name;

public:
	Student(char* name, int age, char* classname)
		: age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->class_name = new char[strlen(classname) + 1];
		strcpy(this->class_name, classname);
	}
	void print(void) const
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		cout << "Class: " << this->class_name << endl;
	}
	char* compareClassname(void)
	{
		return this->class_name;
	}
};

class School
{
	class Student* student_list[100];
	int size = 0;

public:
	void new_c(char* name, int age, char* classname)
	{
		this->student_list[this->size] = new Student(name, age, classname);
		size++;
	}
	void printAll(void)
	{
		cout << "=====print_all=====" << endl;
		for (int k = 0;k < size ;k++)
		{
			student_list[k]->print();
			cout << "----------" << endl;
		}
	}
	void printClass(char* classname)
	{
		int i = 0;
		cout << "=====print_class=====" << endl;
		for (int k = 0;k < size;k++)
		{
			if (student_list[k]->compareClassname() == classname)
			{
				student_list[k]->print();
				cout << "----------" << endl;
				i++;
				break;
			}
			else if (student_list[k]->compareClassname() == classname && (k == size - 1))
				break;
		}
		cout << "Number of classmates : " << i << endl;
	}
	void sortName(void)
	{
		Student* ss[1];

		for (int k = 0;k < size;k++)
		{
			for (int i = 0;i < size-1;i++)
			{
				if (student_list[i]->compareClassname() > student_list[i+1]->compareClassname())
				{
					ss[0] = student_list[i];
					student_list[i] = student_list[i + 1];
					student_list[i + 1] = ss[0];
				}
			}
		}
	}
};

School s;

int main(void)
{
	while (1)
	{
		char choice[100];
		char classname[100];
		int age;
		char name[100];

		scanf("%s", choice);

		if (strcmp(choice, "new_student") == 0)
		{
			scanf("%s %d %s", name, &age, classname);
			s.new_c(name, age, classname);
		}
		else if (strcmp(choice, "sort_by_name") == 0)
		{
			s.sortName();
		}
		else if (strcmp(choice, "print_all") == 0)
		{
			s.printAll();
		}
		else if (strcmp(choice, "print_class") == 0)
		{
			scanf("%s", classname);
			s.printClass(classname);
		}
		else if (strcmp(choice, "exit") == 0)
		{
			break;
		}
	}
}