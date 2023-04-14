/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:07:13 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/14 16:16:15 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	int	i;
	size_t	j;
	std::string res;
	std::string tmp;

	if (ac == 1)
		res = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{	
		i = 0;
		while (++i < ac)
		{
			tmp = av[i];
			j = -1;
			while (++j < tmp.length())
				res += (char)toupper(tmp[j]);
			res += " ";
		}
	}
	std::cout << res << std::endl;
	return (0);
}