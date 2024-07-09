#pragma once
class Person
{
protected:
	int cnp;
	int age;
	char first_name[40];
	char last_name[40];

public:
	~Person();
	Person();
	Person(int age, const char first_name[40], const char last_name[40]);

	int GetCNP() { return this->cnp; };
	int GetAge() { return this->age; };
	char* GetFirstName() { return this->first_name; };
	char* GetLastName() { return this->last_name; };

	virtual void print() {
		std::cout << this->first_name << " " << this->last_name << ": " << this->age << " " << this->cnp << "\n";
	}

	bool operator==(Person& pers);
	bool operator!=(Person& pers);
};

class Worker :
	public Person
{
	char job[20];
	int salary;
public:
	~Worker();
	Worker();
	Worker(int age, const char first_name[40], const char last_name[40], const char job[20], int salary);

	char* GetJob() {
		return this->job;
	}

	int GetSalary() {
		return this->salary;
	}

	void print() {
		std::cout << this->first_name << " " << this->last_name << ": " << this->age << " " << this->cnp << " " << this->job << " " << this->salary << "\n";
	}
};
