
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main (void)
{
	PhoneBook	p;
	int			i = 0;
	std::string input;

	std::cout <<"Welcome to PhoneBook," <<std::endl;
	while (!std::cin.eof())
	{
		std::cout<< "	pls insert a cmd: ADD, SEARCH, EXIT"
			<< std::endl;
		getline(std::cin, input);
		
		if (input == "ADD")
		{
			if (i >= 8)
				i = 0;
			p.add(i++);
		}
		else if (input == "SEARCH")
			p.search(i);
		else if (input == "EXIT")
			exit(0);
		else
			std::cout<< "Invalid input!" << std::endl;
	}
	return 0;
}