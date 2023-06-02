#include "BitCoinExchange.hpp"

// Constructors
BitCoinExchange::BitCoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitCoinExchange\e[0m" << std::endl;
}

BitCoinExchange::BitCoinExchange(std::string csv_file)
{
	std::cout << "\e[0;33mCSV File Constructor called of BitCoinExchange\e[0m" << std::endl;
	std::ifstream data;
	
	data.open ("data.csv");
	if(!data.is_open())
		throw OpenException();
	for (std::string line; std::getline(data, line);)
	{
		{
			std::string			svalue;
			double				value;
			std::string			date;
			std::stringstream	ss(line);
			ss.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			std::getline(ss, date, ',');
			std::getline(ss, svalue);
			std::stringstream streamValue(svalue);
			streamValue.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			streamValue >> value;
			
		}
	}
}


BitCoinExchange::BitCoinExchange(const BitCoinExchange &copy)
{
	*this = copy;
	std::cout << "\e[0;33mCopy Constructor called of BitCoinExchange\e[0m" << std::endl;
}


// Destructor
BitCoinExchange::~BitCoinExchange()
{
	std::cout << "\e[0;31mDestructor called of BitCoinExchange\e[0m" << std::endl;
}


// Operators
BitCoinExchange & BitCoinExchange::operator=(const BitCoinExchange &assign)
{
	this->_data = assign._data;
	return *this;
}

// Member Function
void	BitCoinExchange::value(std::string fileName)
{
	std::ifstream db;

	db.open ("fileName");
	if(!db.is_open())
		throw OpenException();
	//TODO
}

template <typename T>
void	BitCoinExchange::value(std::string date, T amount)
{
	//TODO
}

// Exception
const char*	BitCoinExchange::OpenException::what() const throw()
{
	return ("Bad Open ");
}
