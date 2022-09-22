#include "Contact.hpp"

void	Contact::set_id(int id)
{
    this->id = id;
}

void	Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

int	Contact::get_id(void)
{
	return this->id;
}

std::string	Contact::get_first_name(void)
{
	return this->first_name;
}

std::string	Contact::get_last_name(void)
{
	return this->last_name;
}

std::string	Contact::get_nickname(void)
{
	return this->nickname;
}

std::string	Contact::get_phone_number(void)
{
	return phone_number;
}

std::string	Contact::get_darkest_secret(void)
{
	return this->darkest_secret;
}

int	Contact::check_phone_number(std::string phone_number)
{
	int	i = 0;

	while (phone_number[i])
	{
		if (i > 10 || !isdigit(phone_number[i]))
			return 0;
		i++;
	}
	if (i != 10)
		return 0;
	return 1;
}

int	Contact::check_space(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] != 32)
			return 1;
		i++;
	}
	return 0;
}