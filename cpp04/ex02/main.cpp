/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:33:10 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 17:07:36 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	{	
		std::cout << "\e[1;34m############## DEEP COPY BRAIN TEST ##############\e[0m" << std::endl;
		std::cout << std::endl;

		Brain 	b ;
		b.setIdea("beep", 0);
		b.setIdea("beep", 1);
		b.setIdea("beep", 2);
		Brain 	a(b);
		
		std::cout << std::endl;
		b.setIdea("boop", 0);
		std::cout << b.getIdea(0) << std::endl;
		std::cout << b.getIdea(1) << std::endl;
		std::cout << b.getIdea(2) << std::endl;
		std::cout << std::endl;
		std::cout << a.getIdea(0) << std::endl;
		std::cout << a.getIdea(1) << std::endl;
		std::cout << a.getIdea(2) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\e[1;34m############## SUBJECT TEST ##############\e[0m" << std::endl;
		std::cout << std::endl;
		const AAnimal* j = new Dog();
		std::cout << std::endl;
		const AAnimal* i = new Cat();
		
		std::cout << std::endl;
		j->makeSound();
		i->makeSound();
		std::cout << std::endl;
		delete j;//should not create a leak
		std::cout << std::endl;
		delete i;
	}
	{
		std::cout << "\e[1;34m############## DEEP COPY CAT TEST ##############\e[0m" << std::endl;
		std::cout << std::endl;	

		Cat 	b ;
		b.getBrain()->setIdea("beep", 0);
		b.getBrain()->setIdea("beep", 1);
		b.getBrain()->setIdea("beep", 2);
		Cat 	a(b);
		
		std::cout << std::endl;
		b.getBrain()->setIdea("boop", 0);
		std::cout << b.getBrain()->getIdea(0) << std::endl;
		std::cout << b.getBrain()->getIdea(1) << std::endl;
		std::cout << b.getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;
		std::cout << a.getBrain()->getIdea(0) << std::endl;
		std::cout << a.getBrain()->getIdea(1) << std::endl;
		std::cout << a.getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;
	}
		{
		std::cout << "\e[1;34m############## DEEP COPY DOG TEST ##############\e[0m" << std::endl;
		std::cout << std::endl;	

		AAnimal	*b = new Dog();
		b->getBrain()->setIdea("beep", 0);
		b->getBrain()->setIdea("beep", 1);
		b->getBrain()->setIdea("beep", 2);
		AAnimal 	*a = new Dog(*(Dog *)b);


		std::cout << std::endl;
		b->getBrain()->setIdea("boop", 0);
		std::cout << b->getBrain()->getIdea(0) << std::endl;
		std::cout << b->getBrain()->getIdea(1) << std::endl;
		std::cout << b->getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;
		std::cout << a->getBrain()->getIdea(0) << std::endl;
		std::cout << a->getBrain()->getIdea(1) << std::endl;
		std::cout << a->getBrain()->getIdea(2) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\e[1;34m############## ASKED TEST ##############\e[0m" << std::endl;
		std::cout << std::endl;

		AAnimal	*array[4];

		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				std::cout << std::endl;
			if (i < 2)
				array[i] = new Dog;
			else
				array[i] = new Cat;
		}
		std::cout << std::endl;
		for (int i = 0; i < 4; i++)
			array[i]->makeSound();
		std::cout << std::endl;
		for (int i = 0; i < 4; i++)
			delete array[i];
	}
	return 0;
}