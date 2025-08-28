#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
public:
	void setFirstName(const std::string& str);
	std::string getFirstName() const;

	void setLastName(const std::string& str);
	std::string getLastName() const;

	void setNickName(const std::string& str);
	std::string getNickName() const;

	void setPhoneNumber(const std::string& str);
	std::string getPhoneNumber() const;

	void setDarkestSecret(const std::string& str);
	std::string getDarkestSecret() const;
};

#endif