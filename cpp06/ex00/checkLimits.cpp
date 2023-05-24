/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLimits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:14:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/24 23:28:19 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

float checkLimitf(std::string toConvert)
{
	if (toConvert == "+inff" || toConvert == "+inf")
	{
			return (std::numeric_limits<float>::infinity());
	}
	if (toConvert == "-inff" || toConvert == "-inf")
	{
			return (-1 * std::numeric_limits<float>::infinity());
	}
	return (std::numeric_limits<double>::quiet_NaN());
}

double checkLimit(std::string toConvert)
{
	if (toConvert == "+inff" || toConvert == "+inf")
	{
			return (std::numeric_limits<double>::infinity());
	}
	if (toConvert == "-inff" || toConvert == "-inf")
	{
			return (-1 * std::numeric_limits<double>::infinity());
	}
	return (std::numeric_limits<double>::quiet_NaN());
}