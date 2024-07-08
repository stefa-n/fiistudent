#include <iostream>
#include "Person.h"

int main()
{
	std::cout << "oop_homework \n";

	std::cout << "CERINTA 1 \n";
	std::cout << "Constructori:\n";
	Person john;
	Person jane(23, "Jane", "Doe");
	
	std::cout << "Metode:\n";
	std::cout << john.GetFirstName() << " " << john.GetLastName() << "; " << jane.GetFirstName() << " " << jane.GetLastName() << "\n";

	std::cout << "Operatori:\n";
	std::cout << "== " << (john == jane) << "\n";
	std::cout << "!= " << (john != jane) << "\n";

	// TODO: Cerinta 2

	// TODO: Cerinta 3
}
