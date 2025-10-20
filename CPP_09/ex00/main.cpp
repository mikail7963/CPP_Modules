#include "BitcoinExchange.hpp"

int inputYearCheck(std::string &line)
{
	int year;
	std::stringstream ss;
	ss << line.substr(0,4);
	ss >> year;
	if (year < 2009 || year > 2022)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	return (1);
}

int inputMonthCheck(std::string &line)
{
	int month;
	std::stringstream ss;
	ss.clear();
	ss.str("");
	ss << line.substr(5,7);
	ss >> month;
	if (month < 1 || month > 12)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	return (1);
}

int inputDayCheck(std::string &line)
{
	int day;
	std::stringstream ss;

	ss.clear();
	ss.str("");
	ss << line.substr(8,9);
	ss >> day;
	if (day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (0);
	}
	return (1);
}

int inputLineCheck(std::string &line)
{
	if (line[4] != '-' || line[7] != '-')
	{
		std::cout << "Error: invalid date format" << std::endl;
		return (0);
	}
	if (!inputYearCheck(line) 
		|| !inputMonthCheck(line)
		|| !inputDayCheck(line))
		return (0);
	return (1);
}

void readFile(std::ifstream &file, BitcoinExchange &btc)
{
	std::string line;
	std::getline(file, line);
	std::getline(file, line);
	while (!file.eof())
	{
		if (!inputLineCheck(line))
		{
			getline(file,line);
			continue;
		}
		btc.FindBtc(line);
		getline(file,line);	
	}
	return;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong argument Usage:" << std::endl;
		std::cout << "./btc <file>" << std::endl;
		return (1);
	}
	std::ifstream file("data.csv");
	if (!file.is_open())
		std::cout << "No data.csv" << std::endl;
	std::ifstream argFile(argv[1]);
	if (!argFile.is_open())
		std::cout << "File can't open" << std::endl;
	std::string line;
	BitcoinExchange btc;
	btc.AddData(file);
	readFile(argFile, btc);
	return (0);
}
