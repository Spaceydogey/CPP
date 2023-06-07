/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:08:43 by hdelmas           #+#    #+#             */
/*   Updated: 2023/06/07 22:54:15 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>
# include <deque>

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

double elapsed(struct timeval	begin, struct timeval	end)
{
	long seconds = end.tv_sec - begin.tv_sec;
    // long nanoseconds = end.tv_nsec - begin.tv_nsec;
	long microseconds = end.tv_usec - begin.tv_usec;
    // double elapsed = seconds*1e9 + nanoseconds;
    double elapsed = seconds + microseconds*1e-6;
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
	
	std::cout << "\033[36mdeque : \033[0m" << std::endl;

	// Sort
	// clock_gettime(CLOCK_REALTIME, &dBegin);
	gettimeofday(&dBegin, 0);
	dSorted = FJADeque(d);
	// clock_gettime(CLOCK_REALTIME, &dEnd);
	gettimeofday(&dEnd, 0);
	delapsed  = elapsed(dBegin, dEnd);

	std::cout << "Before : ";
	ft_print(d);
	std::cout << "After : ";
	ft_print(dSorted);
	std::cout << "Time elapsed : " << delapsed << " s" << std::endl;
	
	std::cout  << std::endl;
	
	std::cout << "\033[36mvector : \033[0m" << std::endl;
	
	// Sort
	// clock_gettime(CLOCK_REALTIME, &vBegin);
	gettimeofday(&vBegin, 0);
	vSorted = FJAVector(v);
	gettimeofday(&vEnd, 0);
	// clock_gettime(CLOCK_REALTIME, &vEnd);
	velapsed  = elapsed(vBegin, vEnd);
	
	std::cout << "Before : ";
	ft_print(v);
	std::cout << "After : ";
	ft_print(vSorted);
	std::cout << "Time elapsed : " << velapsed << " s" << std::endl;
}