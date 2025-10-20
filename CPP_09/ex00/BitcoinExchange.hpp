#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange &operator=(const BitcoinExchange& ins);
	~BitcoinExchange();
	void AddData(std::ifstream &file);
	void FindBtc(std::string &line);
};



#endif