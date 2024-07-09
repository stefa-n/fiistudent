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

	// TODO: Derive 3 new classes which should extend the base class by adding at least 2 attributes ✅, 2 different methods ✅ and by re-implementing 1 method from the base class ✅
	
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

	// TODO: Cerinta 3
	std::cout << "CERINTA 3 \n";
}
