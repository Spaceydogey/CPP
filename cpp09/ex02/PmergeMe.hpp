/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:25 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/06 14:03:17 by hdelmas          ###   ########.fr       */
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
T	mergePairs(T &lhs, T &rhs) //we assume that container size is even
{
	T			res;
	typename T::iterator	max_lhs;
	typename T::iterator	max_rhs;
	
	while (!(lhs.empty() && rhs.empty()))
	{
		max_lhs = std::max_element(lhs.begin(), lhs.end());
		max_rhs = std::max_element(rhs.begin(), rhs.end());
		if (rhs.empty() || (*max_lhs > *max_rhs && !lhs.empty() ))
		{
			res.insert(res.begin(), max_lhs - 1, max_lhs + 1);
			lhs.erase(max_lhs - 1, max_lhs + 1);	
		}
		else
		{
			res.insert(res.begin(), max_rhs - 1, max_rhs + 1);	
			rhs.erase(max_rhs - 1, max_rhs + 1);	
		}
	}
	return (res);
}

template <typename T>
T	&orderPairs(T &container) //we assume that container size is even
{
	// We need to mergesort container on the 2n + 1 values so we have a container ordered by pairs size every 2n+1 indexes are the max value of a pair
	int size = container.size();
	if (size > 2) // division of container for the merge sort
	{
		int split = (size / 2);
		if (split % 2 == 1)		//if Split is odd we need to take into account that we want to merge sort with pairs
			--split;
			
		// Split into 2 T
		T	lhs(container.begin(), container.begin() + split);
		T	rhs(container.begin() + split, container.end());
		
		// Recursion to merge sort each split
		lhs = orderPairs(lhs);
		rhs = orderPairs(rhs);
		
		// Merge
		container = mergePairs(lhs, rhs);
	}
	return (container);
}
#endif