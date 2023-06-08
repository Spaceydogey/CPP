/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:25 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 13:41:14 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>

class OverflowException : std::exception
{
	public:
		virtual const char* what() const throw();	
};

std::vector<int> 	FJAVector(std::vector<int> v);
std::deque<int> 	FJADeque(std::deque<int> d);
int					parsing(int ac, char **av, std::vector<int> &v, std::deque<int> &d);

template <typename T>
void	ft_print(T &container)
{
	std::cout << "{ ";
	for (size_t i = 0; i < container.size() - 1; i++)
        std::cout << container[i] << ", ";
    std::cout << container[container.size() - 1] << " ";
    std::cout << "};" << std::endl;
}

//split
template <typename T>
T	split(T &main, int leftover) 
{
	T						pend;
	typename T::iterator	it = main.begin();
	size_t					halfSize = main.size() / 2;
	
	while (main.size() > halfSize)
	{
		pend.push_back(*it);
		it = main.erase(it);
		it += 1;
	}
	if (leftover >= 0)
		pend.push_back(leftover);
	return (pend);
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
		if (rhs.empty() || (!lhs.empty() && *max_lhs > *max_rhs))
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
	size_t size = container.size();
	if (size > 2) // division of container for the merge sort
	{
		size_t split = (size / 2);
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

template <typename T>
T	insert(T &main, T &pend)
{
	std::vector<size_t>		toInsert;
	size_t					size = pend.size();
	size_t					i = 0;
	size_t					jac = 1;
	size_t					lastJac = 0;
	size_t					lastLastJac = 0;
	
	for (size_t j = 0; j < size; ++j)
		toInsert.push_back(j + 1);
	while (i < size && jac <= size)
	{
		
		if (jac < lastJac) //overflow protection
			throw OverflowException();
	
		for (size_t j = jac; j > lastJac; --j)
		{
			main.insert(std::lower_bound(main.begin(), main.begin() + jac + i - 1, pend[j - 1]), pend[j - 1]);
			toInsert.erase(toInsert.begin() + jac - 1 - i);
			i++;
		}
		lastLastJac = lastJac;
		lastJac = jac;
		jac = lastJac + 2*lastLastJac;
	}
	//add after jac
	for(std::vector<size_t>::const_reverse_iterator it = toInsert.rbegin(); it !=  toInsert.rend(); it++)
	{
		main.insert(std::lower_bound(main.begin(), main.begin() + *it + i - 1, pend[*it - 1]),  pend[*it - 1]);
		i++;
	}
	
	return (main);
}

#endif