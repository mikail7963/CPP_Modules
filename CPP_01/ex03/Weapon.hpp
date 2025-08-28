#include <string>
#include <iostream>

#ifndef __WEAPON_H__
#define __WEAPON_H__


class Weapon
{
	private:
		std::string type;
	public:
	Weapon(std::string name);
	~Weapon();
	const std::string GetType() const;
	void setType(const std::string type);
};

#endif
