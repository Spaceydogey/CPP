/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:08:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/07 16:28:12 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>
# include <deque>


int	main(int ac, char** av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: " << "Usage: ./PmergeMe 'ARRAY'" << std::endl;
		return (1);
	}
	std::stringstream	ss(av[1]);
	std::vector<int>	v;
	std::deque<int>		d;

	for (std::string val; std::getline(ss, val, ' ');)
	{
		std::stringstream	sVal(val);
		int					toInsert;
		sVal >> toInsert;
		if (sVal.fail() || toInsert < 0)
		{
			std::cout << "Error : Bad Input" << std::endl;
			return (1);
		}	
		v.push_back(toInsert);
	}
	// std::vector<int> v;
	// for (int i = 0; i < 8; ++i)
		// v.push_back(i);
	// v[0] = 11;
	// v[1] = 10;
	// v[2] = 0;
	// v[3] = 6;
	// v[4] = 8;
	// v[5] = 14;
	// v[6] = 1;
	// v[7] = 1434;
	
	FJAVector(v);
	// ft_print(v);

}