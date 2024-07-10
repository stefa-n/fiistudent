#pragma once
#include <vector>

class Person
{
protected:
	int cnp;
	int age;
	char first_name[40];
	char last_name[40];

	void GenerateCNP(int& variable)
	{
		int cnp = 0;
		for (int i = 0; i <= 3; i++)
		{
			cnp += ((rand() % (8)) + 1); // seed-ul lui rand va fi mereu 1, deci daca se da restart la program va da aceleasi numere mereu
			cnp *= 10;
		}

		variable = cnp;
	}

public:
	~Person()
	{
		std::cout << "Deconstructorul pentru clasa \"Person\" a fost apelat (" << this->first_name << " " << this->last_name << ")\n";
	};
	Person()
	{
		std::cout << "Constructorul pentru clasa \"Person\" fara argumente a fost apelat: ";
		this->age = rand() % 30;
		GenerateCNP(this->cnp);
		strcpy_s(this->first_name, "John");
		strcpy_s(this->last_name, "Doe");

		this->print();
	};
	Person(int age, const char first_name[40], const char last_name[40])
	{
		std::cout << "Constructorul pentru clasa \"Person\" cu argumente a fost apelat: ";
		this->age = age;
		GenerateCNP(this->cnp);
		strcpy_s(this->first_name, first_name);
		strcpy_s(this->last_name, last_name);

		this->print();
	};

	int GetCNP() { return this->cnp; };
	int GetAge() { return this->age; };
	char* GetFirstName() { return this->first_name; };
	char* GetLastName() { return this->last_name; };
	void SetFirstName(char name[40]) { strcpy_s(this->first_name, name); }
	void SetLastName(char name[40]) { strcpy_s(this->last_name, name); }

	virtual void print() {
		std::cout << this->first_name << " " << this->last_name << ": " << this->age << " " << this->cnp << "\n";
	}

	bool operator==(Person& pers)
	{
		if (this->cnp == pers.cnp)
			return true;
		return false;
	};
	bool operator!=(Person& pers)
	{
		if (this->cnp != pers.cnp)
			return true;
		return false;
	};
};

class Worker :
	public Person
{
	char job[20];
	int salary;
public:
	~Worker()
	{
		std::cout << "Deconstructorul pentru clasa \"Worker\" a fost apelat (" << this->first_name << " " << this->last_name << ")\n";
	};
	Worker()
	{
		std::cout << "Constructorul pentru clasa \"Worker\" fara argumente a fost apelat: ";
		this->age = rand() % 30;
		GenerateCNP(this->cnp);
		strcpy_s(this->first_name, "John");
		strcpy_s(this->last_name, "Doe");

		this->salary = 3000;
		strcpy_s(this->job, "Constructor");

		this->print();
	};
	Worker(int age, const char first_name[40], const char last_name[40], const char job[20], int salary)
	{
		std::cout << "Constructorul pentru clasa \"Worker\" cu argumente a fost apelat: ";
		this->age = age;
		GenerateCNP(this->cnp);
		strcpy_s(this->first_name, first_name);
		strcpy_s(this->last_name, last_name);

		this->salary = salary;
		strcpy_s(this->job, job);

		this->print();
	};

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

class City
{
	char name[40];
	std::vector<Person> persoane;

public:
	~City() {
		std::cout << "Destructorul pentru clasa \"City\" a fost apelat\n";
	};
	City()
	{
		std::cout << "Constructorul pentru clasa \"City\" fara argumente a fost apelat\n";
		strcpy_s(this->name, "Piatra-Neamt");
	};
	City(const char name[40], std::vector<Person> persoane)
	{
		std::cout << "Constructorul pentru clasa \"City\" cu argumente a fost apelat\n";
		strcpy_s(this->name, name);
		this->persoane = persoane;
	};
	void SetName(const char name[40])
	{
		std::cout << "Numele orasului a fost schimbat din " << this->name << " in " << name << "\n";
		strcpy_s(this->name, name);
	}
	void AddPerson(Person& person)
	{
		std::cout << "Am adaugat pe " << person.GetFirstName() << " " << person.GetLastName() << " in lista locuitorilor" << "\n";
		this->persoane.push_back(person);
	}
	void EditNameOfPersonWithIndex(int index, char first_name[40], char last_name[40])
	{
		std::cout << "Editez numele persoanei " << this->persoane[index].GetFirstName() << " " << this->persoane[index].GetLastName() << " in " << first_name << " " << last_name << "\n";
		this->persoane[index].SetFirstName(first_name);
		this->persoane[index].SetLastName(last_name);
	}
	void print()
	{
		for (auto& person : persoane)
		{
			person.print();
		}
	}
};