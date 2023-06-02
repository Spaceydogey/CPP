#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <map>


class BitCoinExchange
{
	private:
		std::map<std::string, double>	_data;
		
	public:
		// Constructors
		BitCoinExchange();
		BitCoinExchange(std::string csvFile);
		BitCoinExchange(const BitCoinExchange &copy);
		
		// Destructor
		~BitCoinExchange();
		
		// Operators
		BitCoinExchange & operator=(const BitCoinExchange &assign);
		
		// Member Funtion
		void	value(std::string fileName);
		template <typename T>
		void	value(std::string date, T amount);


	// Exception
	class OpenException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

};

#endif