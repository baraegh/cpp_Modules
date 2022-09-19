
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		void		add(int id);
		void		search(int size);
		void		check_first_name(int id);
		void		check_last_name(int id);
		void		check_nickname(int id);
		void		check_phone_number(int id);
		void		check_darkest_secret(int id);
		void		diplay_contacts(int size);
		std::string	resize_str(std::string str);
		int			check_arg(std::string str);
		void		display_info(int id);
};

#endif
