/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:45:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/18 15:47:29 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int		size;
	Zombie *beep;

	size = 5;
	beep = zombieHorde(size, "boop");
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " ";
		beep[i].announce();
	}
	delete [] beep;
}