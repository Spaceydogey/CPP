/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:22 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 09:20:21 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
    {
        ClapTrap Clap("Clap");
        ScavTrap Scav("Scav");
        FragTrap Frag("Frag");
        
        std::cout << "\e[0;32mTesting Clap attack\e[0m" << std::endl;
        Clap.attack("an innocent looking sheep");
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Clap beRepaired\e[0m" << std::endl;
        Clap.beRepaired(0);
        Clap.beRepaired(1);
        Clap.beRepaired(5);
        Clap.beRepaired(4294967295);
        Clap.beRepaired(-2);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        Clap.beRepaired(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Clap takeDamage\e[0m" << std::endl;
        Clap.takeDamage(0);
        Clap.takeDamage(1);
        Clap.takeDamage(5);
        Clap.takeDamage(2000);
        Clap.takeDamage(4294967295);
        Clap.takeDamage(0);
        std::cout << std::endl;

        std::cout << "\e[0;32mTesting Scav attack\e[0m" << std::endl;
        Scav.attack("a cute looking otter");
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav beRepaired\e[0m" << std::endl;
        Scav.beRepaired(0);
        Scav.beRepaired(1);
        Scav.beRepaired(5);
        Scav.beRepaired(4294967295);
        Scav.beRepaired(-2);
        Scav.beRepaired(0);
        Scav.beRepaired(0);
        Scav.beRepaired(0);
        Scav.beRepaired(0);
        Scav.beRepaired(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav guardGate\e[0m" << std::endl;
        Scav.guardGate();
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav takeDamage\e[0m" << std::endl;
        Scav.takeDamage(0);
        Scav.takeDamage(1);
        Scav.takeDamage(5);
        Scav.takeDamage(2000);
        Scav.takeDamage(4294967295);
        Scav.takeDamage(0);
        std::cout << std::endl;

        std::cout << "\e[0;32mTesting Frag attack\e[0m" << std::endl;
        Frag.attack("a sleepy cat");
        std::cout << std::endl;
   
        std::cout << "\e[0;32mTesting Frag beRepaired\e[0m" << std::endl;
        Frag.beRepaired(0);
        Frag.beRepaired(1);
        Frag.beRepaired(5);
        Frag.beRepaired(4294967295);
        Frag.beRepaired(-2);
        Frag.beRepaired(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Frag guardGate\e[0m" << std::endl;
        Frag.highFivesGuys();
        Frag.highFivesGuys();
        Frag.highFivesGuys();
        Frag.highFivesGuys();
        Frag.highFivesGuys();
        Frag.highFivesGuys();
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Frag takeDamage\e[0m" << std::endl;
        Frag.takeDamage(0);
        Frag.takeDamage(1);
        Frag.takeDamage(5);
        Frag.takeDamage(2000);
        Frag.takeDamage(4294967295);
        Frag.takeDamage(0);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        ClapTrap *bsptr;
        ScavTrap derived;
        
        std::cout << std::endl;
        bsptr = &derived;
        bsptr->attack("TEST");
        std::cout << std::endl;
    }

}