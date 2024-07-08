#include <iostream>
#include "Person.h"

void GenerateCNP(int &variable)
{
	int cnp = 0;
	for (int i = 0; i <= 3; i++)
	{
		cnp += ((rand() % (8)) + 1); // seed-ul lui rand va fi mereu 1, deci daca se da restart la program va da aceleasi numere mereu
		cnp *= 10;
	}

	variable = cnp;
}

Person::~Person()
{
	std::cout << "Deconstructorul pentru clasa \"Person\" a fost apelat (" << this->first_name << " " << this->last_name << ")\n";
}

Person::Person()
{
	std::cout << "Constructorul pentru clasa \"Person\" fara argumente a fost apelat: ";
	this->age = rand() % 30;
	GenerateCNP(this->cnp);
	strcpy_s(this->first_name, "John");
	strcpy_s(this->last_name, "Doe");

	std::cout << " V: " << this->age << "; CNP: " << this->cnp << "; FN: " << this->first_name << "; LN: " << this->last_name << "\n";
}

Person::Person(int age, const char first_name[40], const char last_name[40])
{
	std::cout << "Constructorul pentru clasa \"Person\" cu argumente a fost apelat: ";
	this->age = age;
	GenerateCNP(this->cnp);
	strcpy_s(this->first_name, first_name);
	strcpy_s(this->last_name, last_name);

	std::cout << " V: " << this->age << "; CNP: " << this->cnp << "; FN: " << this->first_name << "; LN: " << this->last_name << "\n";
}

int Person::GetAge()
{
	return this->age;
}

int Person::GetCNP()
{
	return this->cnp;
}

char* Person::GetFirstName()
{
	return this->first_name;
}

char* Person::GetLastName()
{
	return this->last_name;
}

bool Person::operator==(Person &pers)
{
	if (this->cnp == pers.cnp)
		return true;
	return false;
}

bool Person::operator!=(Person &pers)
{
	if (this->cnp != pers.cnp)
		return true;
	return false;
}