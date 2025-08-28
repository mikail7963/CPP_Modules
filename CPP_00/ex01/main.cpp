#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string input;
	Contact contact;
	PhoneBook PhoneBook;

	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return 0;
		if (input[0] == '\n')
			continue;
		if (input == "ADD")
			PhoneBook.addContact();
		else if (input == "SEARCH")
			PhoneBook.searchContacts();
		else if (input == "EXIT")
			return 0;
		else
			continue;
	}
}