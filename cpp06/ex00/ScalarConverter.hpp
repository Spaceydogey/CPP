/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:01:31 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 11:23:03 by hdelmas          ###   ########.fr       */
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
		static int	fromChar(std::string toConvert);
		static int	fromInt(std::string toConvert);
		static int	fromFloat(std::string toConvert);
		static int	fromDouble(std::string toConvert);
		static int	fromUndefined(std::string toConvert);
		

	public:
		static int	convert(std::string toConvert);
		
};

#endif