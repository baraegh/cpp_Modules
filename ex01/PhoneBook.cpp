#include "PhoneBook.hpp"

void	PhoneBook::check_first_name(int id)
{
	std::string	input;

	while (1)
	{
		std::cout<< "  insert the first name: ";
		getline(std::cin, input);
		if (input != "\0" && input != "\n"
			&& this->contact[id].check_space(input))
		{
			this->contact[id].set_first_name(input);
			input.clear();
			break;
		}
		input.clear();
		std::cout<< "Invalid name!" << std::endl;
	}
}

void	PhoneBook::check_last_name(int id)
{
	std::string	input;

	while (1)
	{
		std::cout<< "  insert the last name: ";
		getline(std::cin, input);
		if (input != "\0" && input != "\n"
			&& this->contact[id].check_space(input))
		{
			this->contact[id].set_last_name(input);
			input.clear();
			break;
		}
		input.clear();
		std::cout<< "Invalid name!" << std::endl;
	}
}

void	PhoneBook::check_nickname(int id)
{
	std::string	input;

	while (1)
	{
		std::cout<< "  insert the nickname: ";
		getline(std::cin, input);
		if (input != "\0" && input != "\n"
			&& this->contact[id].check_space(input))
		{
			this->contact[id].set_nickname(input);
			input.clear();
			break;
		}
		input.clear();
		std::cout<< "Invalid nickname!" << std::endl;
	}
}

void	PhoneBook::check_phone_number(int id)
{
	std::string	input;

	while (1)
	{
		std::cout<< "  insert the phone number: ";
		getline(std::cin, input);
		if (input != "\0" && input != "\n"
			&& this->contact[id].check_phone_number(input))
		{
			this->contact[id].set_phone_number(input);
			input.clear();
			break;
		}
		input.clear();
		std::cout<< "Invalid phone number!" << std::endl;
	}
}

void	PhoneBook::check_darkest_secret(int id)
{
	std::string	input;

	while (1)
	{
		std::cout<< "  insert the darkest secret: ";
		getline(std::cin, input);
		if (input != "\0" && input != "\n"
			&& this->contact[id].check_space(input))
		{
			this->contact[id].set_darkest_secret(input);
			input.clear();
			break;
		}
		input.clear();
		std::cout<< "Invalid darkest secret!" << std::endl;
	}
}

void	PhoneBook::add(int	id)
{
	this->contact[id].set_id(id);
	check_first_name(id);
	check_last_name(id);
	check_nickname(id);
	check_phone_number(id);
	check_darkest_secret(id);
	std::cout << "\n* new contact was inserted successfully *\n" << std::endl;
}

int	PhoneBook::check_arg(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (isdigit(str[i]))
			return 0;
	}
	return 1;
}

void	PhoneBook::display_info(int id)
{
	if (!this->contact[id].get_first_name().empty())
	{
		std::cout << "\n	index: " << id << std::endl;
		std::cout << "	first name: " << this->contact[id].get_first_name() << std::endl;
		std::cout << "	last name: " << this->contact[id].get_last_name() << std::endl;
		std::cout << "	nickmname: " << this->contact[id].get_nickname() << std::endl;
		std::cout << "	phone number: " << this->contact[id].get_phone_number() << std::endl;
		std::cout << "	darkest secret: " << this->contact[id].get_darkest_secret() << std::endl;
	}
	else
		std::cout << "	Invalid arg!\n";
}

void	PhoneBook::search(int size)
{
	std::string	input;

	diplay_contacts(size);
	while (1)
	{
		std::cout << "insert an id or type EXIT: ";
		getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (!check_arg(input) && atoi(input.c_str()) < 8
			&& atoi(input.c_str()) >= 0)
				display_info(atoi(input.c_str()));
		else
			std::cout << "	invlaid arg!\n";
	}
	std::cout << std::endl;
}

std::string	PhoneBook::resize_str(std::string str)
{
	if (str.length() <= 10)
		return str;
	str.erase(10, str.length() - 10);
	str[9] = '.';
	return str;
}

void	PhoneBook::diplay_contacts(int size)
{
	std::cout << std::endl;
	std::cout << "|----------|----------|----------|----------|\n";
	std::cout << "|index     |first name|last name |nickname  |\n";
	std::cout << "|----------|----------|----------|----------|\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "|" << std::left << std::setw(10)
			<< this->contact[i].get_id() << "|";
		std::cout << std::setw(10) << this->resize_str(this->contact[i].get_first_name())
			<< "|";
		std::cout << std::setw(10) << this->resize_str(this->contact[i].get_last_name()) 
			<< "|";
		std::cout << std::setw(10) << this->resize_str(this->contact[i].get_nickname()) 
			<< "|" << std::endl;
		std::cout << "|----------|----------|----------|----------|\n";
	}
	std::cout << std::endl;
}