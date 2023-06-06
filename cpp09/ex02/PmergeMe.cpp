/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/06 19:40:48 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* OverflowException::what() const throw()
{
	return ("Overflow");
}

std::vector<int> FJAVector(std::vector<int> v)
{
	std::vector<int> pend;

	ft_print(v);
	makePairs(v);
	ft_print(v);
	orderPairs(v);
	ft_print(v);
	pend = split(v, 12);
	std::cout << "main : ";
	ft_print(v);
	std::cout << "pend : ";
	ft_print(pend);
	insert(v, pend);
	ft_print(v);
	return (v);
}