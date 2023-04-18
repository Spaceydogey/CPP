/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:45:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/18 14:53:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *heap1;
	Zombie stack1("stack1");
	
	heap1 = newZombie("heap1");
	heap1->announce();
	stack1.announce();
	randomChump("boop");

	{
		Zombie *heap2;
		Zombie stack2("stack2");
		heap2 = newZombie("heap2");
		
		stack2.announce();
		stack1.announce();
		heap2->announce();
		heap1->announce();
		delete heap2;
	}
	
	stack1.announce();
	heap1->announce();
	delete heap1;
}