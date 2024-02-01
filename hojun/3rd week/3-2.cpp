#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#pragma warning (disable: 4267)
using namespace std;

class student
{
private:
	char* name;
	int age;
	char* class_name;

public:
	student(char* name, int age, char* class_name)
	{
		int len = strlen(name);
		this->name = new char[len + 1];
		strcpy(this->name, name);
		len = strlen(class_name);
		this->class_name = new char[len + 1];
		strcpy(this->class_name, class_name);
		this->age = age;
	}
	~student()
	{
		delete[] name;
		delete[] class_name;
	}
	char* return_name()
	{
		return this->name;
	}
	char* return_class()
	{
		return this->class_name;
	}
	void copy(student * s)
	{
		delete[] this->name;
		delete[] this->class_name;
		int len = strlen(s->name);
		this->name = new char[len + 1];
		strcpy(this->name, s->name);
		len = strlen(s->class_name);
		this->class_name = new char[len + 1];
		strcpy(this->class_name, s->class_name);
		this->age = s->age;
	}
	void print()
	{
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		cout << "Class: " << this->class_name << endl;
		cout << "----------\n";
	}
};

class school
{
private:
	class student* stu_list[100]{};
	int size = 0;

public:
	~school()
	{
		for (int i = 0; i < size; i++)
			delete stu_list[i];
	}
	void new_stu(char* name, int age, char* class_name)
	{
		this->stu_list[this->size] = new class student(name, age, class_name);
		size++;
	}
	void sort()
	{
		int k = 0;
		for (int i = 0; i < size - 1; i++)
		{
			k = i;
			for (int j = i + 1; j < size; j++)
			{
				if (cmp(stu_list[k]->return_name(), stu_list[j]->return_name()) > 0)
					k = j;
			}
			if (k != i)
				swap(stu_list[i], stu_list[k]);
		}
	}
	int cmp(char* s1, char* s2)
	{
		return strcmp(s1, s2);
	}
	void print_class(char* stu_class)
	{
		int num_cla_mate = 0;
		cout << "=====print_class=====\n";
		for (int i = 0; i < size; i++)
		{
			if (!strcmp(stu_list[i]->return_class(), stu_class))
			{
				stu_list[i]->print();
				num_cla_mate++;
			}
		}
		cout << "Number of classmates: " << num_cla_mate << "\n";
	}
	void print_all()
	{
		cout << "=====print_all=====\n";
		for (int i = 0; i < size; i++)
			stu_list[i]->print();
	}
	void swap(student* s1, student* s2)
	{
		student* tmp = new student(s1->return_name(), 0, s1->return_class());
		tmp->copy(s1);
		s1->copy(s2);
		s2->copy(tmp);
	}
};

int main()
{
	school* kw = new school;//kw university allocation
	char input[20];
	char name[20];
	int age;
	char class_name[20];

	while (1)
	{
		cin >> input;

		if (!strcmp(input, "exit")) break;//break point
		else if (!strcmp(input, "new_student"))
		{
			cin >> name >> age >> class_name;
			kw->new_stu(name, age, class_name);
		}
		else if (!strcmp(input, "sort_by_name"))
			kw->sort();
		else if (!strcmp(input, "print_all"))
			kw->print_all();
		else if (!strcmp(input, "print_class"))
		{
			char cla[20];
			cin >> cla;
			kw->print_class(cla);
		}
	}

	delete kw;
}