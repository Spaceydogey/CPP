/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:28:11 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/29 00:26:15 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	{	
		std::vector<int> vect;
	
		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(3);
		std::cout << easyfind< std::vector<int> >(vect, 4) << std::endl;
		std::cout << easyfind< std::vector<int> >(vect, 2) << std::endl;
	}
	{
		std::list<int> lst;
	
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(2);
		std::cout << easyfind< std::list<int> >(lst, 4) << std::endl;
		std::cout << easyfind< std::list<int> >(lst, 2) << std::endl;
	}
}