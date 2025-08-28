#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

bool isNumber(const std::string& str) 
{
    int i = 0;

	if (str.empty())
        return false;
	while(str[i])
	{
        if (!std::isdigit(str[i]))
            return false;
		i++;
    }
    return true;
}

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

void PhoneBook::addContact()
{
	while (true)
	{
		std::string name;
		std::cout << "NAME: ";
		std::getline(std::cin, name);
		if (std::cin.eof())
			return ;
		if (name.empty())
			continue;
		contacts[contactCount % 8].setFirstName(name);
		break;
	}

	while (true)
	{
		std::string LastName;
		std::cout << "LASTNAME: ";
		std::getline(std::cin, LastName);
		if (std::cin.eof())
			return ;
		if (LastName[0] == '\n')
			continue;
		if (LastName.empty())
			continue;
		contacts[contactCount % 8].setLastName(LastName);
		break;
	}

	while (true)
	{
		std::string NickName;
		std::cout << "NICKNAME: ";
		std::getline(std::cin, NickName);
		if (std::cin.eof())
			return ;
		if (NickName[0] == '\n')
			continue;
		if (NickName.empty())
			continue;
		contacts[contactCount % 8].setNickName(NickName);
		break;
	}

	std::string PhoneNumber;
	while (true)
	{
		std::cout << "PHONE NUMBER: ";
		std::getline(std::cin, PhoneNumber);
		if (std::cin.eof())
			return ;
		if (PhoneNumber[0] == '\n')
			continue;
		if (PhoneNumber.empty())
			continue;
		if (!isNumber(PhoneNumber))
		{
			std::cout << "Invalid phone number" << std::endl;
			continue;
		}
		contacts[contactCount % 8].setPhoneNumber(PhoneNumber);
		break;
	}

	while (true)
	{
		std::string DarkestSecret;
		std::cout << "DARKEST SECRET:";
		std::getline(std::cin, DarkestSecret);
		if (std::cin.eof())
			return ;
		if (DarkestSecret.empty())
			continue;
		contacts[contactCount % 8].setDarkestSecret(DarkestSecret);
		break ;
	}
	contactCount++;
}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}


void PhoneBook::searchContacts()
{
	if (this->contactCount == 0)
	{
		std::cout << "No Contact" << std::endl;
		return ;
	}

	int i = 0;
	std::string input;
	int count = (contactCount < 8) ? contactCount : 8;
	int number;

	std::cout << "|" << std::setw(10) << "Index"
	<< "|"<< std::setw(10) << "First Name"
	<< "|" << std::setw(10) << "Last Name" 
	<< "|" << std::setw(10) << "Nickname"
	<< "|" << std::endl;

	while (i < count)
	{
		std::cout << "|" << std::setw(10) << i << "|"
		<< std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
		<< std::setw(10) << truncate(contacts[i].getLastName()) << "|"
		<< std::setw(10) << truncate(contacts[i].getNickName()) << "|" << std::endl;
		i++;
	}
	while (true)
	{
		std::cout << "enter an index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			return ;
		}
		if (input.empty())
			continue;
		if (!isNumber(input))
		{
			std::cout << "Invalid input" << std::endl;
			continue;
		}
		number = input[0] - 48;
		if (number >= count || input[1])
		{
			std::cout << "Invalid index" << std::endl;
			continue;
		}
		std::cout << "First Name: " << contacts[number].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts[number].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[number].getNickName() << std::endl;
		std::cout << "Phone Number: " << contacts[number].getPhoneNumber() << std::endl;
		std::cout << "Dark Secret: " << contacts[number].getDarkestSecret() << std::endl;
		break;
	}
}
