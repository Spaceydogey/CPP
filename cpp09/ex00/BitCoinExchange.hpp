/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:25:09 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/04 17:54:19 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <map>
# include <algorithm>
# include <exception>


class BitCoinExchange
{
	private:
		std::map<std::string, double>	_data;
		static bool						check_date(std::string date);
		static void						parseInit(std::ifstream *db, std::string collum1, std::string collum2, char charset);
		void							print(std::string date);
		void							print(float value);
		void							print();
		void							print(std::string date, float value);
		
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
		double	value(std::string date, float value) const;


	// Exception
	class OpenException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

	class ConversionException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
	
	class DateException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};
	class CsvException : public std::exception
	{
		public:
			virtual const char* what() const throw();	
	};

};

#endif