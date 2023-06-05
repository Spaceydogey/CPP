/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:08:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/05 23:19:52 by hdelmas          ###   ########.fr       */
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
	ft_print(v);
	makePairs(v);
	ft_print(v);
	orderPairs(v);
}