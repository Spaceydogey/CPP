/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:35:40 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 16:25:51 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>
#define FLOOR_SIZE 5

int main()
{
	int				floor_last_id = 0;
    AMateria		*floor[FLOOR_SIZE];
    IMateriaSource*	src = new MateriaSource();
    
	for (int i = 0;i < FLOOR_SIZE; i++)
		floor[i] = NULL;
	src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    std::cout << std::endl;
    ICharacter* notMe = new Character(*(Character *)me);
    std::cout << std::endl;

    if (floor_last_id >= FLOOR_SIZE)
	{
		for (int i = 0;i < FLOOR_SIZE; i++)
			delete floor[i];
		floor_last_id = 0;
	}
	floor[floor_last_id] = ((Character *)me)->getMateria(0);
	floor_last_id++;	
	me->unequip(0);
	floor[floor_last_id - 1]->use(*me);
    std::cout << std::endl;

	tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl;
    
    std::cout << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << std::endl;
    
    std::cout << "me use" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    std::cout << std::endl;
    
    delete me;

    std::cout << std::endl;
    std::cout << "notMe use" << std::endl;
    notMe->use(0, *bob);
    notMe->use(1, *bob);
    notMe->use(2, *bob);
    notMe->use(3, *bob);
    notMe->use(4, *bob);
    std::cout << std::endl;
    delete bob;
    delete notMe;
    delete src;
	for (int i = 0;i < FLOOR_SIZE; i++)
		if (floor[i])
			delete floor[i];
    return 0;
}