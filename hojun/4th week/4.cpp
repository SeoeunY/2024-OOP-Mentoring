#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class person
{
protected:
	int age;
	char name[32];

public:
	void say() { cout << "Hi"; }
};

class student :public person
{
protected:
	char student_num[11];
	char major[32];
	int schoolyear;

public:
	int get_age() { return this->age; }
	char* get_name() { return this->name; }
	char* get_student_num() { return this->student_num; }
	char* get_major() { return this->major; }
	int get_schoolyear() { return this->schoolyear; }
	void set_age(int age) { this->age = age; }
	void set_name(char* name) { strcpy(this->name, name); }
	void set_student_num(char* student_num) { strcpy(this->student_num, student_num); }
	void set_major(char* major) { strcpy(this->major, major); }
	void set_schoolyear(int year) { this->schoolyear = year; }
	void say()
	{
		cout << "I¡¯m a student of KW University.\n";
		cout << "My name is " << get_name() << ".\n";
		cout << "My student number is " << get_student_num() << ".\n";
		cout << "I'm " << get_age() << " years old and I'm a ";
		switch (get_schoolyear())
		{
		case 1:	cout << "freshman.\n"; break;
		case 2:	cout << "sophomore.\n"; break;
		case 3:	cout << "junior.\n"; break;
		case 4:	cout << "senior.\n"; break;
		default: break;
		}
		cout << "I¡¯m majoring in " << get_major() << ".\n";
	}
};

class professor :public person
{
protected:
	char professor_num[11];
	char major[32];

public:
	int get_age() { return this->age; }
	char* get_name() { return this->name; }
	char* get_professor_num() { return this->professor_num; }
	char* get_major() { return this->major; }
	void set_age(int age) { this->age = age; }
	void set_name(char* name) { strcpy(this->name, name); }
	void set_professor_num(char* professor_num) { strcpy(this->professor_num, professor_num); }
	void set_major(char* major) { strcpy(this->major, major); }
	void say()
	{
		cout << "I¡¯m a professor of KW University.\n";
		cout << "My name is " << get_name() << ".\n";
		cout << "My professor number is " << get_professor_num() << ".\n";
		cout << "I'm " << get_age() << " years old.\n";
		cout << "I¡¯m majoring in " << get_major() << ".\n";
	}
};

int main()
{
	char name[20] = {};
	int age = 0;
	char num[11] = {};
	char major[32] = {};
	int schoolyear = 0;

	cout << "=====Enter student information=====\n";
	cout << "Enter the age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter the name: ";
	cin.getline(name, 19);
	cout << "Enter the student number: ";
	cin >> num;
	cin.ignore();
	cout << "Enter the major: ";
	cin.getline(major, 31);
	cout << "Enter the school year: ";
	cin >> schoolyear;

	class student* sky = new student;
	sky->set_age(age);
	sky->set_major(major);
	sky->set_name(name);
	sky->set_schoolyear(schoolyear);
	sky->set_student_num(num);

	cout << "\n";
	cout << "\n";

	cout << "=====Enter professor information=====\n";
	cout << "Enter the age: ";
	cin >> age;
	cin.ignore();
	cout << "Enter the name: ";
	cin.getline(name, 19);
	cout << "Enter the professor number: ";
	cin >> num;
	cin.ignore();
	cout << "Enter the major: ";
	cin.getline(major, 31);

	class professor* soo = new professor;
	soo->set_age(age);
	soo->set_major(major);
	soo->set_name(name);
	soo->set_professor_num(num);

	cout << "\n";
	cout << "\n";

	sky->say();
	cout << "\n";
	cout << "\n";
	soo->say();

	delete sky;
	delete soo;
}