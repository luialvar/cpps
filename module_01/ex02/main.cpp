#include <string>
#include <iostream>

int main()
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string &stringREF = var;

	// The memory address of the string variable.
	std::cout << &var << "\n";

	// The memory address held by stringPTR.
	std::cout << stringPTR << "\n";

	// The memory address held by stringREF.
	std::cout << &stringREF << "\n";

	// The value of the string variable.
	std::cout << var << "\n";

	// The value pointed to by stringPTR.
	std::cout << *stringPTR << "\n";

	// The value pointed to by stringREF.
	std::cout << stringREF << " \n";

}