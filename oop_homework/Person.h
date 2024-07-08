#pragma once
class Person
{
	// 1st exercise
	// Design a base class which shall contain at least 4 attributes, 4 methods, 2 Constructors, 1 Destructor and 2 operators
	int cnp;
	int age;
	char first_name[40];
	char last_name[40];

public:
	~Person();
	Person();
	Person(int age, const char first_name[40], const char last_name[40]);

	int GetCNP();
	int GetAge();
	char* GetFirstName();
	char* GetLastName();

	bool operator==(Person& pers);
	bool operator!=(Person& pers);
};

