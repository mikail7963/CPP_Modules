#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()  {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	this->data = obj.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& ins)
{
	if (this != &ins)
	{
		this->data = getData();
	}
	return (*this);
}


std::map<std::string, float> BitcoinExchange::getData() const
{
	return data;
}


void BitcoinExchange::AddData(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string strValue;
	float value;
	std::stringstream ss;
	
	getline(file, line);
	getline(file, line);
	while (!file.eof())
	{
		date = line.substr(0,10);
		strValue = line.substr(11);
		ss.clear();
		ss.str("");
		ss << strValue;
		ss >> value;
		this->data.insert(std::make_pair(date,value));
		getline(file, line);
	}	
}

void BitcoinExchange::FindBtc(std::string &line)
{
	float inputValue;
	std::string lineDate = line.substr(0,10);
	std::map<std::string, float>::iterator it;

	it = this->data.upper_bound(lineDate);
    if (it != this->data.begin())
        --it;
    else
    {
        std::cout << "Error: date is before the earliest data." << std::endl;
        return;
    }
	std::stringstream ss;
	ss << &line[line.find('|') + 1];
	ss >> inputValue;
	if (static_cast<long>(inputValue) > 2147483647)
	{
		std::cout << "Error: too large a number."  << std::endl;
		return;
	}
	if (inputValue < 0 || inputValue > 1000)
	{
		std::cout << "Error: not a positive number."  << std::endl;
		return;
	}
	float value = it->second;
	std::cout << line.substr(0,10) << " => " << inputValue << " = " << value * inputValue << std::endl;
}
