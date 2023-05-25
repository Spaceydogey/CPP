/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:18:09 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 11:10:05 by hdelmas          ###   ########.fr       */
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
	if (_float == static_cast<float>(_int))
		floatEnd = ".0";
	if (_double == static_cast<double>(_int))
		doubleEnd = ".0";
	if (_float == HUGE_VALF)
		floatStart = "+";
	if (_double == HUGE_VAL)
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

int	ScalarConverter::fromChar(std::string toConvert)
{
	const char 		_char = toConvert[0];
	const int		_int = static_cast<int>(toConvert[0]);
	const float		_float = static_cast<float>(toConvert[0]);
	const double	_double = static_cast<double>(toConvert[0]);
	
	ScalarConverter::print(_char, _int, _float, _double);
	return (0);
}

int	ScalarConverter::fromInt(std::string toConvert)
{
	std::istringstream ss(toConvert); 
	int	converted;

	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Int overflow" <<std::endl;
		return (1);
	}

	const char 		_char = checkChar(converted);
	const int		_int = converted;
	const float		_float = static_cast<float>(converted);
	const double	_double = static_cast<double>(converted);
	
	ScalarConverter::print(_char, _int, _float, _double);
	return (0);
}

int	ScalarConverter::fromFloat(std::string toConvert)
{
	std::istringstream ss(toConvert.erase(toConvert.size() - 1)); 
	float	converted;

	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Float overflow" <<std::endl;
		return (1);
	}
	
	const char 		_char = checkChar(static_cast<int>(converted));
	const int		_int = static_cast<int>(converted);
	const float		_float = converted;
	const double	_double = static_cast<double>(converted);
	
	ScalarConverter::print(_char, _int, _float, _double);
	return (0);
}

int	ScalarConverter::fromDouble(std::string toConvert)
{
	std::istringstream ss(toConvert); 
	double	converted;
	
	ss >> converted;
	if (ss.fail())
	{
		std::cout << "Error: Double overflow" <<std::endl;
		return (1);
	}

	const char 		_char = checkChar(static_cast<int>(converted));
	const int		_int = static_cast<int>(converted);
	const float		_float = static_cast<float>(converted);
	const double	_double = converted;
	
	ScalarConverter::print(_char, _int, _float, _double);
	return (0);
}

int ScalarConverter::fromUndefined(std::string toConvert)
{
	const char 		_char = 0;
	const int		_int = 0;
	const float		_float = checkLimitf(toConvert);
	const double	_double = checkLimit(toConvert);

	ScalarConverter::print(_char, _int, _float, _double);
	return (0);
}


int	ScalarConverter::convert(std::string toConvert)
{
	int	type;

	type = getType(toConvert);
	switch (type)
	{
		case CHAR:
			std::cout << "##CHAR##" << std::endl;
			return (ScalarConverter::fromChar(toConvert));
		case INT:
			std::cout << "##INT##" << std::endl;
			return (ScalarConverter::fromInt(toConvert));
		case FLOAT:
			std::cout << "##FLOAT##" << std::endl;
			return (ScalarConverter::fromFloat(toConvert));
		case DOUBLE:
			std::cout << "##DOUBLE##" << std::endl;
			return (ScalarConverter::fromDouble(toConvert));
		case UNDEFINED:
			std::cout << "##UNDEFINED##" << std::endl;
			return (ScalarConverter::fromUndefined(toConvert));
		default:
			std::cerr << "Error: Wrong argument" << std::endl;
			return (1);
	}
}
