#include <iostream>
#include "Person.h"

int main()
{
	// Design a base class which shall contain at least 4 attributes ✅, 4 methods ✅, 2 Constructors ✅, 1 Destructor ✅ and 2 operators ✅
	std::cout << "oop_homework \n";

	std::cout << "CERINTA 1 \n";
	std::cout << "Constructori:\n";
	Person *john = new Person();
	Person *jane = new Person(23, "Jane", "Doe");

	
	std::cout << "Metode:\n";
	std::cout << john->GetFirstName() << " " << john->GetLastName() << "; " << jane->GetFirstName() << " " << jane->GetLastName() << "\n";

	std::cout << "Operatori:\n";
	std::cout << "== " << (john == jane) << "\n";
	std::cout << "!= " << (john != jane) << "\n";

	std::cout << "Destructori:\n";
	delete john;
	delete jane;

	// Derive 3 new classes which should extend the base class by adding at least 2 attributes ✅, 2 different methods ✅ and by re-implementing 1 method from the base class ✅
	
	std::cout << "Constructori:\n";
	Worker *wjohn = new Worker();
	Worker *wjane = new Worker(23, "Jane", "Doe", "Programator", 5000);

	std::cout << "Metode:\n";
	std::cout << "Job:" << wjohn->GetJob() << ";\n";
	std::cout << "Salary:" << wjohn->GetSalary() << ";\n";
	std::cout << "Metoda reimplementata (print):";
	wjohn->print();

	std::cout << "Destructori:\n";
	delete wjohn;
	delete wjane;

	// Create a class that works with objects of the base class; this new class shall contain at least a method / operator to add items of base class type, to print and to modify the added items
	
	std::cout << "---------------------------------\n";
	Person *johnny = new Person(23, "Johnny", "Doe");
	Person *janey = new Person(23, "Janey", "Doe");
	std::cout << "---------------------------------\n";
	
	std::cout << "CERINTA 3 \n";
	City *Iasi = new City();
	Iasi->SetName("Iasi");
	
	std::cout << "Method to add items:\n";
	Iasi->AddPerson(*johnny);
	Iasi->AddPerson(*janey);

	delete johnny;
	delete janey;

	std::cout << "Print the added items:\n";
	Iasi->print();

	delete Iasi;
}
