/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:42:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/26 19:44:38 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	i[5] = {0,1,2,3,4};
	char c[5] = {'H','E','L','L','O'};
	float f[5] = {0.0,1.0,2.0,3.0,4.0};
	double d[5] = {0.0,1.0,2.0,3.0,4.0};

	ft_print<int>(i, 5);	
	ft_print<char>(c, 5);	
	ft_print<float>(f, 5);	
	ft_print<double>(d, 5);
	std::cout << std::endl;

	iter<int, void>(i, 5, boop<int>);
	iter<char, void>(c, 5, boop<char>);
	iter<float, void>(f, 5, boop<float>);
	iter<double, void>(d, 5, boop<double>);
	std::cout << std::endl;
	
	ft_print<int>(i, 5);	
	ft_print<char>(c, 5);	
	ft_print<float>(f, 5);	
	ft_print<double>(d, 5);
}