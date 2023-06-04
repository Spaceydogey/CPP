/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:25:12 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/04 16:46:26 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

// Constructors
BitCoinExchange::BitCoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitCoinExchange\e[0m" << std::endl;
}

BitCoinExchange::BitCoinExchange(std::string csvFile)
{
	std::cout << "\e[0;33mCSV File Constructor called of BitCoinExchange\e[0m" << std::endl;
	
	std::ifstream db;
	db.open(csvFile.c_str());
	if(!db.is_open())
		throw OpenException();
	
	BitCoinExchange::parseInit(&db, "date", "exchange_rate", ',');

	for (std::string line; std::getline(db, line);)
	{
		line.erase(remove(line.begin(),line.end(), ' '), line.end()); 
		{
			std::string			strValue;
			double				value;
			std::string			date;
			std::stringstream	ss(line);
						
			std::getline(ss, date, ',');
			std::getline(ss, strValue);

			if (!BitCoinExchange::check_date(date))
				throw DateException();
				
			std::stringstream streamValue(strValue);
			streamValue >> value;
			if (streamValue.fail())	
				throw ConversionException();
				
			this->_data.insert(std::pair<std::string, double>(date, value));
		}
	}
	db.close();
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

	db.open(fileName.c_str());
	if(!db.is_open())
		throw OpenException();
	BitCoinExchange::parseInit(&db, "date", "value", '|');
	
	for (std::string line; std::getline(db, line);)
	{
		line.erase(remove(line.begin(),line.end(), ' '), line.end());
		{
			std::string			strValue;
			float				value;
			std::string			date;
			std::stringstream	ss(line);
			
			if (std::find(line.begin(), line.end(), '|') != line.end())	
			{	
				std::getline(ss, date, '|');
				std::getline(ss, strValue);
				if (strValue != "")
				{
					if (!BitCoinExchange::check_date(date))
						this->print(date);
					else
					{
						std::stringstream streamValue(strValue);
						streamValue >> value;
						if (streamValue.fail())	
							this->print();
						else if (value > 1000.f || value < 0.f)
							this->print(value);
						else
							this->print(date, value);
					}
				}
				else
					this->print("no value");		
			}
			else
				this->print("no charset");
		}
	}
	db.close();
}

double	BitCoinExchange::value(std::string date, float value) const
{
	//We assume that the date and value is correct
	typename std::map<std::string, double>::const_iterator it = this->_data.lower_bound(date);
	if (it->first != date)
		it--;
	return (it->second * value);
}


// Private Functions

bool	BitCoinExchange::check_date(std::string date)
{
	std::stringstream	sDate(date);
	std::string			stringYear;
	std::string			stringMon;
	std::string			stringDay;
	int					year;
	int					mon;
	int					day;
	
	std::getline(sDate, stringYear, '-');
	std::getline(sDate, stringMon, '-');
	std::getline(sDate, stringDay);
	
	std::stringstream sYear(stringYear);
	std::stringstream sMon(stringMon);
	std::stringstream sDay(stringDay);

	sYear >> year;
	sMon >> mon;
	sDay >> day;
	
	// std::cout << year << " " << mon << " " << day << std::endl;
	//Initial check
	// Check if the conversion is possible aka the string is a number
	if (sYear.fail() || sMon.fail() || sDay.fail())
		return (false);
	// Check the lower bound values
	if (year < 2009 || mon < 1 || day < 1)
		return (false);
	// Check the upper bound values (year is maxint and if the conversion overflow sYear >> year fails and i think year maxint is a fine limit)
	if (mon > 12 || day > 31)
		return false;
	//February check
	if (mon == 2)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) //is leap year
			return (day <= 29);
		return (day <= 28);
	}
	//30 days month check (April june september november)
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
		return (day <= 30);
	return (true);
}


void	BitCoinExchange::parseInit(std::ifstream *db, std::string collum1, std::string collum2, char charset)
{
	std::string col1;
	std::string col2;
	std::string first;
	std::getline(*db, first);
	first.erase(remove(first.begin(),first.end(), ' '), first.end()); 
	std::stringstream	sfirst(first);
	std::getline(sfirst, col1, charset);
	std::getline(sfirst, col2);
	if (col1 != collum1 ||  col2 != collum2)
		throw CsvException();	
}

void	BitCoinExchange::print(std::string date)
{
	std::cout << "Error : bad input => " << date << std::endl;
}

void	BitCoinExchange::print(float value)
{
	if (value > 1000.f)
		std::cout << "Error : number too large => ";
	else 
		std::cout << "Error :number is negative => ";
	std::cout << value << std::endl;
}

void	BitCoinExchange::print()
{
	std::cout << "Error : not a number" << std::endl;
}

void	BitCoinExchange::print(std::string date, float value)
{
	double amount = this->value(date, value);
	std::cout << date << " => " << value << " = " << amount << std::endl;
}


// Exception
const char*	BitCoinExchange::OpenException::what() const throw()
{
	return ("Bad Open");
}

const char*	BitCoinExchange::ConversionException::what() const throw()
{
	return ("Bad Conversion");
}

const char*	BitCoinExchange::DateException::what() const throw()
{
	return ("Bad Date");
}

const char*	BitCoinExchange::CsvException::what() const throw()
{
	return ("Bad CSV File");
}

