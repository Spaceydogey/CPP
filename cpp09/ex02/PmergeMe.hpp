/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:25 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/05 23:17:25 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <algorithm>

template <typename T>
void	ft_print(T &container)
{
	std::cout << "{ ";
	for (size_t i = 0; i < container.size() - 1; i++)
        std::cout << container[i] << ", ";
    std::cout << container[container.size() - 1] << " ";
    std::cout << "};" << std::endl;
}

template <typename T>
T	&makePairs(T &container) //we assume that container size is even
{	
	typename T::iterator	it = container.begin();
	
	while (it != container.end())
	{
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		it += 2;
	}
	return (container);
}

template <typename T>
T	&orderPairs(T &container) //we assume that container size is even
{
	// We need to mergesort container on the 2n + 1 values so we have a container ordered by pairs size every 2n+1 indexes are the max value of a pair
	//division of container for the merge sort
	int split = (container.size() / 2) - 1;
	if (split % 2 == 0)
		--split;
	T	lhs(container.begin(), container.begin() + split + 1);
	T	rhs(container.begin() + split + 1, container.end());
	std::cout << "lhs = ";
	ft_print(lhs);
	std::cout << "rhs = ";
	ft_print(rhs);
	return (container);
}
#endif