#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Student {
private:
	char* name; // Student's name
	int age; // Student's age
	char* class_name; // Name of the class the student belongs to
	
public:
	// Constructor to initialize Student object
	Student(char* name, int age, char* class_name);

	// Destructor to free dynamically allocated memory
	~Student();

	// Getter function to get student's name
	char* getname();
	
	// Print function to display student information
	void print();

	// Function to check if the student belongs to a specific class
	bool isClassCorrect(char* class_name);
};

class School {
private:
	class Student* student_list[100]; // Array to store pointers to Student objects
	int size = 0;  // Current number of students in the school

public:
	// Function to add a new student to the school
	void new_student(char* name, int age, char* class_name);

	// Function to sort students by their names
	void sort_by_name();

	// Function to print information of all students in the school
	void print_all();

	// Function to print information of students in a specific class
	void print_class(char * class_name);

	// Function to release memory allocated for students and exit the program
	void exit();
};

// Constructor definition for the Student class
Student::Student(char* name, int age, char* class_name) {
	// Dynamically allocate memory for strings and copy values
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->class_name= new char[strlen(class_name) + 1];
	strcpy(this->class_name, class_name);
}

// Destructor definition for the Student class
Student::~Student() {
	// free dynamically allocated memory
	delete[] name;
	delete[] class_name;
}

// Getter function definition for the Student class
char* Student::getname() {
	return name;
}

// Print function definition for the Student class
void Student::print() {
	cout << "Name: " << name << "\nAge: " << age << "\nClass: " << class_name << "\n----------" << endl;
}

// Function to check if the student belongs to a specific class
bool Student::isClassCorrect(char* class_name) {
	return (strcmp(this->class_name, class_name) == 0);
	// if (!strcmp(this->class_name, class_name)) return true;
	// else return false;
}

// Function to add a new student to the school
void School::new_student(char* name, int age, char* class_name) {
	student_list[size++] = new Student(name, age,  class_name);
}

// Function to sort students by their names
void School::sort_by_name() {
	class Student *temp; // Temporary pointer

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			// Strcmp(str1, str2) returns a positive number if str1 precedes str2
			if (strcmp(student_list[i]->getname(), student_list[j]->getname()) > 0) {
				temp = student_list[i];
				student_list[i] = student_list[j ];
				student_list[j ] = temp;
			}
		}
	}
}

// Function to print information of all students in the school
void School::print_all() {
	cout << "=====print_all=====" << endl;
	for (int i = 0; i < size; i++) {
		student_list[i]->print();
	}
}

// Function to print information of students in a specific class
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

// Function to release memory allocated for students and exit the program
void School::exit() {
	for (int i = 0; i < size; i++) {
		delete student_list[i];
	}
}

// Main function
int main() {
	School school; // Create a School object
	char command[100]; // Array to store user commands
	char name[100];
	int age;
	char class_name[100];

	// Main program loop
	while (true) {
		cin >> command;

		// Check user command and perform corresponding actions
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