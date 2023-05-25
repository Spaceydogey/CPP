/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkLimits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:14:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 11:02:02 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00.hpp"

float checkLimitf(std::string toConvert)
{
	if (toConvert == "+inff" || toConvert == "+inf")
	{
			return (HUGE_VALF);
	}
	if (toConvert == "-inff" || toConvert == "-inf")
	{
			return (-1 * HUGE_VALF);
	}
	return (std::numeric_limits<double>::quiet_NaN());
}

double checkLimit(std::string toConvert)
{
	if (toConvert == "+inff" || toConvert == "+inf")
	{
			return (HUGE_VAL);
	}
	if (toConvert == "-inff" || toConvert == "-inf")
	{
			return (-1 * HUGE_VAL);
	}
	return (std::numeric_limits<double>::quiet_NaN());
}