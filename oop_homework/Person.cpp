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

// (De/con)structori
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

	this->print();
}

Person::Person(int age, const char first_name[40], const char last_name[40])
{
	std::cout << "Constructorul pentru clasa \"Person\" cu argumente a fost apelat: ";
	this->age = age;
	GenerateCNP(this->cnp);
	strcpy_s(this->first_name, first_name);
	strcpy_s(this->last_name, last_name);

	this->print();
}

Worker::~Worker()
{
	std::cout << "Deconstructorul pentru clasa \"Worker\" a fost apelat (" << this->first_name << " " << this->last_name << ")\n";
}

Worker::Worker()
{
	std::cout << "Constructorul pentru clasa \"Worker\" fara argumente a fost apelat: ";
	this->age = rand() % 30;
	GenerateCNP(this->cnp);
	strcpy_s(this->first_name, "John");
	strcpy_s(this->last_name, "Doe");

	this->salary = 3000;
	strcpy_s(this->job, "Constructor");

	this->print();
}

Worker::Worker(int age, const char first_name[40], const char last_name[40], const char job[20], int salary)
{
	std::cout << "Constructorul pentru clasa \"Worker\" cu argumente a fost apelat: ";
	this->age = age;
	GenerateCNP(this->cnp);
	strcpy_s(this->first_name, first_name);
	strcpy_s(this->last_name, last_name);

	this->salary = salary;
	strcpy_s(this->job, job);

	this->print();
}

// Operatori
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

