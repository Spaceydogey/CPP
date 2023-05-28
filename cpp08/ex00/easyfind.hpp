/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:04:28 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/29 00:12:17 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFINS_HPP

# include  <algorithm>
# include <iostream>
# include <vector>
# include <map>
# include <list>

template<typename T>
bool	easyfind(T container, int toFind)
{
	typename T::iterator	res;
	
	res = std::find(container.begin(), container.end(), toFind);
	if (res == container.end())
	{
		std::cout << "No element found" << std::endl;
		return (false);
	}
	std::cout << "Found : " << *res  << " at " << std::distance(container.begin(), res) << std::endl;
	return (true);
}

#endif