/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:59 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 14:39:14 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* OverflowException::what() const throw()
{
	return ("Overflow");
}

std::vector<int> FJAVector(std::vector<int> v)
{
	std::vector<int>	pend;
	int					leftover = -1;

	if (v.size() % 2 == 1)
	{
		leftover = v[v.size() - 1];
		v.pop_back();
	}	 
	makePairs(v);
	orderPairs(v);
	pend = split(v, leftover);
	insert(v, pend);
	return (v);
}

std::deque<int> FJADeque(std::deque<int> d)
{
	std::deque<int>	pend;
	int				leftover = -1;

	if (d.size() % 2 == 1)
	{
		leftover = d[d.size() - 1];
		d.pop_back();
	}	 
	makePairs(d);
	orderPairs(d);
	pend = split(d, leftover);
	insert(d, pend);
	return (d);
}

bool isStringDigits(const std::string str) {
    for (size_t i = 0; i < str.size(); ++i) 
	{
        if (!std::isdigit(str[i]))
		{
            return (false);
		}
	}
	return (true);
}

int	parsing(int ac, char **av, std::vector<int> &v, std::deque<int> &d)
{
	for (int i = 1; i < ac; ++i)
	{
		int					toInsert;
		std::stringstream	sVal(av[i]);
		
		if (!isStringDigits(av[i]))
		{
			std::cout << "Error : Bad Input" << std::endl;
			return (1);
		}
		sVal >> toInsert;
		if (sVal.fail() || toInsert < 0)
		{
			std::cout << "Error : Bad Input" << std::endl;
			return (1);
		}
		if (std::find(v.begin(), v.end(), toInsert) != v.end())	
		{
			std::cout << "Error : Duplicate Number" << std::endl;
			return (1);
		}
		v.push_back(toInsert);
		d.push_back(toInsert);
	}
	return (0);
}

