/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:33:10 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 14:07:17 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		std::cout << "\e[1;34m##############GOOD TEST##############\e[0m" << std::endl;
		std::cout << std::endl;
		const Animal*	meta = new Animal();
		std::cout  << std::endl;
		const Animal*	j = new Dog();
		std::cout  << std::endl;
		const Animal*	i = new Cat();
		std::cout  << std::endl;
		Dog				dog;
		std::cout  << std::endl;
		Cat				cat;
		Animal			*base;
		
		base = &cat;
		std::cout << std::endl;
		std::cout << "type of j : "<< j->getType() << " " << std::endl;
		std::cout << "type of i : " << i->getType() << " " << std::endl;
		std::cout << "type of cat : " << cat.getType() << " " << std::endl;
		std::cout << "type of base : " << base->getType() << " " << std::endl;
		std::cout << "type of dog : " << dog.getType() << " " << std::endl;
		std::cout << "type of meta : " << meta->getType() << " " << std::endl;
		std::cout << std::endl;
		std::cout << "i sound : ";
		i->makeSound(); //will output the cat sound!
		std::cout << "j sound : ";
		j->makeSound();
		std::cout << "cat sound : ";
		cat.makeSound();
		std::cout << "dog sound : ";
		dog.makeSound();
		std::cout << "base sound : ";
		base->makeSound();
		std::cout << "meta sound : ";
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		std::cout << std::endl;
		delete j;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "\e[1;34m##############WRONG TEST##############\e[0m" << std::endl;
		std::cout << std::endl;
		const WrongAnimal*	meta = new WrongAnimal();
		std::cout  << std::endl;
		const WrongAnimal*	i = new WrongCat();
		std::cout  << std::endl;
		WrongCat			cat;
		WrongAnimal			*base;
		
		base = &cat;
		std::cout << std::endl;
		std::cout << "type of i : " << i->getType() << " " << std::endl;
		std::cout << "type of cat : " << cat.getType() << " " << std::endl;
		std::cout << "type of base : " << base->getType() << " " << std::endl;
		std::cout << "type of meta : " << meta->getType() << " " << std::endl;
		std::cout << std::endl;
		std::cout << "i sound : ";
		i->makeSound(); //will output the cat sound!
		std::cout << "cat sound : ";
		cat.makeSound();
		std::cout << "base sound : ";
		base->makeSound();
		std::cout << "meta sound : ";
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		std::cout << std::endl;
		delete i;
		std::cout << std::endl;
	}
	return 0;
}