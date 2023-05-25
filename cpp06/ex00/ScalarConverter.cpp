/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:09 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 10:02:55 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

void	ScalarConverter::print(const char _char, const int _int,
								const float _float, const double _double)
{
	std::string floatEnd = "";
	std::string doubleEnd = "";
	std::string floatStart = "";
	std::string doubleStart = "";
	std::cout.precision(9);
	if (_float == static_cast<float>(_int))
		floatEnd = ".0";
	if (_double == static_cast<double>(_int))
		doubleEnd = ".0";
	if (_float == std::numeric_limits<float>::infinity())
		floatStart = "+";
	if (_double == std::numeric_limits<double>::infinity())
		doubleStart = "+";
		
	if (_char == 0)
		std::cout << "char: impossible" << std::endl;
	else 
		std::cout << "char: " << _char << std::endl;
	if (_double > 2147483647. || _double < -2147483648. || std::isnan(_double))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << floatStart << _float << floatEnd + "f" << std::endl;
	std::cout << "double: " << doubleStart << _double << doubleEnd << std::endl;
}

void	ScalarConverter::fromChar(std::string toConvert)
{
	const char 		_char = toConvert[0];
	const int		_int = static_cast<int>(toConvert[0]);
	const float		_float = static_cast<float>(toConvert[0]);
	const double	_double = static_cast<double>(toConvert[0]);
	
	ScalarConverter::print(_char, _int, _float, _double);
}

void	ScalarConverter::fromInt(std::string toConvert)
{
	std::istringstream ss(toConvert); 
	int	converted;

	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Int overflow" <<std::endl;
		return ;
	}

	const char 		_char = checkChar(converted);
	const int		_int = converted;
	const float		_float = static_cast<float>(converted);
	const double	_double = static_cast<double>(converted);
	
	ScalarConverter::print(_char, _int, _float, _double);
}

void	ScalarConverter::fromFloat(std::string toConvert)
{
	std::istringstream ss(toConvert.erase(toConvert.size() - 1)); 
	float	converted;

	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Float overflow" <<std::endl;
		return ;
	}
	
	const char 		_char = checkChar(static_cast<int>(converted));
	const int		_int = static_cast<int>(converted);
	const float		_float = converted;
	const double	_double = static_cast<double>(converted);
	
	ScalarConverter::print(_char, _int, _float, _double);
}

void	ScalarConverter::fromDouble(std::string toConvert)
{
	std::istringstream ss(toConvert); 
	double	converted;
	
	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Double overflow" <<std::endl;
		return ;
	}

	const char 		_char = checkChar(static_cast<int>(converted));
	const int		_int = static_cast<int>(converted);
	const float		_float = static_cast<float>(converted);
	const double	_double = converted;
	
	ScalarConverter::print(_char, _int, _float, _double);
}

void ScalarConverter::fromUndefined(std::string toConvert)
{
	const char 		_char = 0;
	const int		_int = 0;
	const float		_float = checkLimitf(toConvert);
	const double	_double = checkLimit(toConvert);

	ScalarConverter::print(_char, _int, _float, _double);
}


int	ScalarConverter::convert(std::string toConvert)
{
	int	type;

	type = getType(toConvert);
	switch (type)
	{
		case CHAR:
			std::cout << "##CHAR##" << std::endl;
			ScalarConverter::fromChar(toConvert);
			return (0);
		case INT:
			std::cout << "##INT##" << std::endl;
			ScalarConverter::fromInt(toConvert);
			return (0);
		case FLOAT:
			std::cout << "##FLOAT##" << std::endl;
			ScalarConverter::fromFloat(toConvert);
			return (0);
		case DOUBLE:
			std::cout << "##DOUBLE##" << std::endl;
			ScalarConverter::fromDouble(toConvert);
			return (0);
		case UNDEFINED:
			std::cout << "##UNDEFINED##" << std::endl;
			ScalarConverter::fromUndefined(toConvert);
			return (0);
		default:
			std::cerr << "Error: Wrong argument" << std::endl;
			return (1);
	}
}
