/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:45:17 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/26 19:13:12 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void	iter(T *addr, size_t size, F (*f)(T &))
{
	if (!addr || !f)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	for (size_t i = 0; i < size; i++)
	{
		f(addr[i]);
	}
}

template<typename T>
void boop(T &a)
{
	std::cout << "boop : "<< a << std::endl;	
}

template<>
void boop(float &a)
{
	a += 19.19;
	std::cout << a << std::endl;
	
}

template<>
void boop(int &a)
{
	a++;
	std::cout << a << std::endl;
}

template<>
void boop(char &a)
{
	a = 'A';
	std::cout << a << std::endl;
}

template<typename T>
void	ft_print(T *addr, size_t size)
{
	for (size_t j = 0; j < size; j++)
		std::cout << addr[j];
	std::cout << std::endl;
}

template<>
void	ft_print(float *addr, size_t size)
{
	for (size_t j = 0; j < size; j++)
		std::cout << addr[j] << " ";
	std::cout << std::endl;
}

#endif