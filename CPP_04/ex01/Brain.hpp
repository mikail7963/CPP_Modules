#pragma once 
#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain &copy);
	Brain& operator=(const Brain& copy);
	
	std::string getIdea(int i) const;
	void setIdea(int i, const std::string& str);

};
