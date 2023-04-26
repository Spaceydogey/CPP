/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:22 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/26 19:08:36 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
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
        std::cout << "\e[0;32mTesting Clap takeDamage\e[0m" << std::endl;
        Clap.takeDamage(0);
        Clap.takeDamage(1);
        Clap.takeDamage(5);
        Clap.takeDamage(2000);
        Clap.takeDamage(4294967295);
        Clap.takeDamage(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Clap beRepaired\e[0m" << std::endl;
        Clap.beRepaired(0);
        Clap.beRepaired(1);
        Clap.beRepaired(5);
        Clap.beRepaired(4294967295);
        Clap.beRepaired(-2);
        Clap.beRepaired(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav attack\e[0m" << std::endl;
        Scav.attack("a cute looking otter");
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav takeDamage\e[0m" << std::endl;
        Scav.takeDamage(0);
        Scav.takeDamage(1);
        Scav.takeDamage(5);
        Scav.takeDamage(2000);
        Scav.takeDamage(4294967295);
        Scav.takeDamage(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav beRepaired\e[0m" << std::endl;
        Scav.beRepaired(0);
        Scav.beRepaired(1);
        Scav.beRepaired(5);
        Scav.beRepaired(4294967295);
        Scav.beRepaired(-2);
        Scav.beRepaired(0);
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Scav guardGate\e[0m" << std::endl;
        Scav.guardGate();
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Frag attack\e[0m" << std::endl;
        Frag.attack("a sleepy cat");
        std::cout << std::endl;
        std::cout << "\e[0;32mTesting Frag takeDamage\e[0m" << std::endl;
        Frag.takeDamage(0);
        Frag.takeDamage(1);
        Frag.takeDamage(5);
        Frag.takeDamage(2000);
        Frag.takeDamage(4294967295);
        Frag.takeDamage(0);
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
    std::cout << std::endl;
    DiamondTrap di("beep");
    std::cout << std::endl;
    std::cout << "Ad = " << di.getAd() << std::endl;
    std::cout << "Hp = " << di.getHp() << std::endl;
    std::cout << "Ep = " << di.getEp() << std::endl;
    std::cout << std::endl;
    std::cout << "\e[0;32mTesting di attack\e[0m" << std::endl;
    std::cout << std::endl;
    di.attack("an innocent looking sheep");
    std::cout << std::endl;
    std::cout << "\e[0;32mTesting di takeDamage\e[0m" << std::endl;

    std::cout << std::endl;
    di.takeDamage(0);
    di.takeDamage(1);
    di.takeDamage(5);
    di.takeDamage(2000);
    di.takeDamage(4294967295);
    di.takeDamage(0);
    std::cout << std::endl;
    std::cout << "\e[0;32mTesting di beRepaired\e[0m" << std::endl;
    di.beRepaired(0);
    di.beRepaired(1);
    di.beRepaired(5);
    di.beRepaired(4294967295);
    di.beRepaired(-2);
    di.beRepaired(0);
    std::cout << std::endl;
    di.whoAmI();
    std::cout << std::endl;
    std::cout << "Ad = " << di.getAd() << std::endl;
    std::cout << "Hp = " << di.getHp() << std::endl;
    std::cout << "Ep = " << di.getEp() << std::endl;
    std::cout << std::endl;
}