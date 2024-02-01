#include <iostream>

using namespace std;

class person
{
protected:
	int age;
	char name[32];

public:
	person();
	~person();
	void say() { cout << "Hi"; }
};

class student :public person
{
protected:
	char studentNum[11];
	char major[32];
	int schoolyear;

public:
	student();
	~student();
	int getAge();
	char* getName();
	char* getStudentNum();
	char* getMajor();
	int getschoolyear
};

person::person()
{

}

person::~person()
{

}