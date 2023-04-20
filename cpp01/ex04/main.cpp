/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:28:58 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/20 15:49:26 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	ft_replace(std::ifstream *ifs, std::string s1,
					std::string s2, std::ofstream *ofs)
{
	std::string		swap;
	std::string		tmp;
	size_t			pos;
	size_t			i;
	
	while (ifs->good())
	{ 
		std::getline(*ifs, swap);
		pos = swap.find(s1);
		while (swap.find(s1) != -1)
		{
			tmp = "";
			i = -1;
			while (++i < pos)
				tmp += swap[i];
			tmp += s2;
			i += s1.length();
			while (swap[i])
				tmp += swap[i++];
			swap = tmp;
			pos = swap.find(s1);
		}
		*ofs << swap;
		if (ifs->good())
			*ofs << std::endl;
	}
}

int	ft_error(int err)
{
	if (err == 1)
		std::cerr << "Error: Bad arguments" << std::endl;
	if (err == 2 || err == 3)
		std::cerr << "Error: Bad open" << std::endl;
	if (err == 4)
		std::cerr << "Error: s1 and s2 cannot be equal to \\0"
			<< std::endl;
	return (err);
}

int	main(int ac, char **av)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		out_name;
	std::string		s1;
	std::string		s2;

	if (ac != 4)
		return (ft_error(1));
	s1 = av[2];
	s2 = av[3];
	if (s1 == "" || s2 == "")
		return (ft_error(4));
	ifs.open(av[1]);
	if (ifs.fail())
		return (ft_error(3));
	out_name = av[1];
	out_name += ".replace";
	ofs.open(out_name.c_str());
	if (ofs.fail())
	{
		ifs.close();
		return (ft_error(3));

	}
	ft_replace(&ifs, s1, s2, &ofs);
	ifs.close();
	ofs.close();
}
