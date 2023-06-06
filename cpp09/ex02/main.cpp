/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:08:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/06 14:03:21 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>

int	main(int ac, char** av)
{
	(void)ac;	
	(void)av;
	std::vector<int> v;
	for (int i = 0; i < 6; ++i)
		v.push_back(i);
	v[0] = 11;
	v[1] = 10;
	v[2] = 9;
	v[3] = 6;
	v[4] = 8;
	v[5] = 1;
	ft_print(v);
	makePairs(v);
	ft_print(v);
	orderPairs(v);
	ft_print(v);

}