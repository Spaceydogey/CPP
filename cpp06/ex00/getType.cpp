/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getType.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:15:02 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/24 22:40:31 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ex00.hpp"

static int	isChar(std::string toConvert)
{
	if (toConvert.size() != 1 
			|| isdigit(toConvert[0])
			|| !isprint(toConvert[0]))
		return (-1);
	return (CHAR);
}

static int	isUndefined(std::string toConvert)
{
	if (toConvert == "-inf" || toConvert == "+inf" || toConvert == "nan"
		|| toConvert == "-inff" || toConvert == "+inff" || toConvert == "nanf")
		return (UNDEFINED);
	return (-1);
}

static int	isNumber(std::string toConvert)
{
	size_t	i;
	size_t	size;
	int		hasPoint;
	int		hasDigit;
	int		hasF;
	
	i = -1;
	hasPoint = 0;
	hasF = 0;
	hasDigit = 0;
	size = toConvert.size();
	while (++i < size)
	{
		if (!(isdigit(toConvert[i])
			|| (hasPoint == 0 && toConvert[i] == '.')
			|| (( i == 0 && (toConvert[i] == '+' || toConvert[i] == '-')))
			|| (toConvert[i] == 'f' && i == toConvert.size() - 1)))
				return (-1);
		if (toConvert[i] == '.')
			hasPoint = 1;
		if (toConvert[i] == 'f')
			hasF = 1;
		if (hasDigit == 0 && isdigit(toConvert[i]))
			hasDigit = 1;
	}
	if (hasDigit == 1 && hasPoint == 0 && hasF == 0)
		return (INT);
	if (hasDigit == 1 && hasPoint == 1 && hasF == 1)
		return (FLOAT);
	if (hasDigit == 1 && hasPoint == 1 && hasF == 0)
		return (DOUBLE);
	return (-1);
}

int	getType(std::string toConvert)
{
	if (toConvert.size() < 1)
		return (-1);
	if (isChar(toConvert) != -1)
		return (CHAR);
	if (isUndefined(toConvert) != -1)
		return (UNDEFINED);
	return (isNumber(toConvert));
}