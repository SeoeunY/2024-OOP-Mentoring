#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Employee {
private:
	char* name;
	int age;
	char* country;
	char* job;

public:
	// Constructor to initialize Employee object
	Employee(char* name, int age, char* country, char* job);

	// Destructor to free dynamically allocated memory
	~Employee();

	// Check if the given name matches the employee's name
	bool isNameCorrect(char* name);

	// Print employee information
	void print();

	// Change employee information
	void change(char* name, int age, char* country, char* job);
};

// Constructor definition
Employee::Employee(char* name, int age, char* country, char* job) {
	// Dynamically allocate memory for strings and copy values
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);

	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);
}

// Destructor definition
Employee::~Employee() {
	// free dynamically allocated memory
	delete[] name;
	delete[] country;
	delete[] job;
}

// Check if the given name matches the employee's name
bool Employee::isNameCorrect(char* name) {
	// Compare the given name with the employee's name
	return (strcmp(this->name, name) == 0);
	// if (!strcmp(this->name, name)) return true;
	// else return false;
}

// Print employee information
void Employee::print() {
	cout <<"Name: " << name << "\nAge: " << age << "\nCountry: " << country << "\nJob: " << job <<"\n----------"<< endl;
}

// Change employee information
void Employee::change(char* name, int age, char* country, char* job) {
	// Free old memory
	delete[] this->name;
	delete[] this->country;
	delete[] this->job;

	// Dynamically allocate new memory and copy values
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->age = age;

	this->country = new char[strlen(country) + 1];
	strcpy(this->country, country);

	this->job = new char[strlen(job) + 1];
	strcpy(this->job, job);
}

int main() {
	// Array to hold pointers to Employee objects
	Employee* employees[10];
	int count = 0; // Counter for the number of employees

	char command[100];
	char name[100];
	char newname[100];
	int age;
	char country[100];
	char job[100];

	// Main program loop
	while (true) {
		cin >> command;

		if (!strcmp(command, "insert")) {
			cin >> name >> age >> country >> job;
			// Check if the array is not full before inserting
			if (count < 10)
				employees[count++] = new Employee(name, age, country, job);
		}
		else if (!strcmp(command, "find")) {
			cin >> name;
			cout << "=====find=====" << endl;
			// Loop through employees and print matching names
			for (int i = 0; i < count; i++) {
				if (employees[i]->isNameCorrect(name))
					employees[i]->print();
			}
		}
		else if (!strcmp(command, "change")) {
			cin >> name >> newname >> age >> country >> job;
			// Loop through employees and change information for matching names
			for (int i = 0; i < count; i++) {
				if (employees[i]->isNameCorrect(name))
					employees[i]->change(newname, age, country, job);
			}
		}
		else if (!strcmp(command, "print")) {
			cout << "=====print====="<< endl;
			// Loop through employees and print their information
			for (int i = 0; i < count; i++) {
				employees[i]->print();
			}
		}
		else if (!strcmp(command, "exit")) {
			break; // Exit the program
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

	// Free memory for all employees
	for (int i = 0; i < count; i++) {
		delete employees[i];
	}

	return 0;
}