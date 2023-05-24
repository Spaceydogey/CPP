/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:01:31 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/24 23:13:06 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "ex00.hpp"

class ScalarConverter
{
	private:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		// Destructor
		~ScalarConverter();
		
		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		static void	print(const char _char, const int _int, const float _float, const double _double);
		static void	fromChar(std::string toConvert);
		static void	fromInt(std::string toConvert);
		static void	fromFloat(std::string toConvert);
		static void	fromDouble(std::string toConvert);
		static void	fromUndefined(std::string toConvert);
		

	public:
		static int	convert(std::string toConvert);
		
};

#endif