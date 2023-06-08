/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:08:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/08 14:04:35 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>
# include <deque>

#include <stdio.h>
#include <sys/time.h>

double elapsed(struct timeval	begin, struct timeval	end)
{
	long seconds = end.tv_sec - begin.tv_sec;
	long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds*1e6 + microseconds;
	return (elapsed);
}
int	main(int ac, char** av)
{

	if (ac < 3)
	{
		std::cout << "Error: " << "Usage: ./PmergeMe array_of_number(at least 2)" << std::endl;
		return (1);
	}
	
	std::vector<int>	v;
	std::vector<int>	vSorted;
	// struct timespec		vBegin, vEnd;
	struct timeval		vBegin, vEnd;
	double				velapsed;
	std::deque<int>		d;
	std::deque<int>		dSorted;
	// struct timespec		dBegin, dEnd;
	struct timeval		dBegin, dEnd;
	double				delapsed;
	
	std::cout << "\033[33mStarting parsing\033[0m" << std::endl;
	if (parsing(ac, av, v, d))
		return (1);
	std::cout << "\033[31mParsing done\033[0m" << std::endl;
	
	std::cout << std::endl;
	

	// Sort deque
	gettimeofday(&dBegin, 0);
	dSorted = FJADeque(d);
	gettimeofday(&dEnd, 0);
	delapsed  = elapsed(dBegin, dEnd);

	// Sort vector
	gettimeofday(&vBegin, 0);
	vSorted = FJAVector(v);
	gettimeofday(&vEnd, 0);
	velapsed  = elapsed(vBegin, vEnd);
	// Print
	std::cout << "Before : ";
	ft_print(d);
	std::cout << "After std::vector : ";
	ft_print(vSorted);
	std::cout << "After std::deque : ";
	ft_print(dSorted);

	std::cout << "Time elapsed for std::deque : " << delapsed << " us" << std::endl;
	std::cout << "Time elapsed for std::vector : " << velapsed << " us" << std::endl;
	std::cout << "Size before : " << d.size() << std::endl;
	std::cout << "Size std::vector : " << vSorted.size() << std::endl;
	std::cout << "Size std::deque : " << dSorted.size() << std::endl;
	std::cout << "Is std::vector sorted : " << std::is_sorted(vSorted.begin(), vSorted.end()) << std::endl;
	std::cout << "Is std::deque sorted : " << std::is_sorted(dSorted.begin(), dSorted.end()) << std::endl;
}