#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Student {
private:
	char* name;
	int age;
	char* class_name;
	
public:
	Student(char* name, int age, char* class_name);
	~Student();
	char* getname();
	void print();
	bool isClassCorrect(char* class_name);
};

class School {
private:
	class Student* student_list[100]; 
	int size = 0;

public:
	void new_student(char* name, int age, char* class_name);
	void sort_by_name();
	void print_all();
	void print_class(char * class_name);
	void exit();
};

Student::Student(char* name, int age, char* class_name) {
	// Dynamically allocate memory for strings and copy values
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->class_name= new char[strlen(class_name) + 1];
	strcpy(this->class_name, class_name);
}

// Destructor definition
Student::~Student() {
	// free dynamically allocated memory
	delete[] name;
	delete[] class_name;
}

char* Student::getname() {
	return name;
}

void Student::print() {
	cout << "Name: " << name << "\nAge: " << age << "\nClass: " << class_name << "\n----------" << endl;
}

bool Student::isClassCorrect(char* class_name) {
	return (strcmp(this->class_name, class_name) == 0);
	// if (!strcmp(this->class_name, class_name)) return true;
	// else return false;
}

void School::new_student(char* name, int age, char* class_name) {
	student_list[size++] = new Student(name, age,  class_name);
}

void School::sort_by_name() {
	class Student *temp;
	for (int i = 0; i < size-1; i++) {
		for (int j = i; j < i - 1; j++) {
			if (strcmp(student_list[i]->getname(), student_list[j]->getname()) > 0) {
				temp = student_list[i];
				student_list[i] = student_list[j ];
				student_list[j ] = temp;
			}
		}
	}
}

void School::print_all() {
	cout << "=====print_all=====" << endl;
	for (int i = 0; i < size; i++) {
		student_list[i]->print();
	}
}

void School::print_class(char* class_name) {
	int numberOfClassmates = 0;
	cout << "=====print_class=====" << endl;
	for (int i = 0; i < size; i++) {
		if (student_list[i]->isClassCorrect(class_name)) {
			student_list[i]->print();
			numberOfClassmates++;
		}
	}
	cout << "Number of classmates : " << numberOfClassmates << endl;
}

void School::exit() {
	for (int i = 0; i < size; i++) {
		delete student_list[i];
	}
}

int main() {
	School school;
	char command[100];
	char name[100];
	int age;
	char class_name[100];

	while (true) {
		cin >> command;

		if (!strcmp(command, "new_student")) {
			cin >> name >> age >> class_name;
			school.new_student(name, age, class_name);
		}
		else if (!strcmp(command, "sort_by_name")) {
			school.sort_by_name();
		}
		else if (!strcmp(command, "print_all")) {
			school.print_all();
		}
		else if (!strcmp(command, "print_class")) {
			cin >> class_name;
			school.print_class(class_name);
		}
		else if (!strcmp(command, "exit")) {
			school.exit();
			break;
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
	return 0;
}