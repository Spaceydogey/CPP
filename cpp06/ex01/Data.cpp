/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:37:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 16:08:16 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	return;
}

Data::Data(const Data &copy)
{
	(void)copy;
	return;
}

Data::~Data()
{
	return;
}

Data & Data::operator=(const Data &assign)
{
	(void)assign;
	return *this;
}

