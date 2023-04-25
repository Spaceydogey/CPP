/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:49:22 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/25 16:07:04 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap trap("trap");
    
    std::cout << "\e[0;32mTesting attack\e[0m" << std::endl;
    trap.attack("an innocent looking sheep");
    std::cout << std::endl;
    std::cout << "\e[0;32mTesting takeDamage\e[0m" << std::endl;
    trap.takeDamage(0);
    trap.takeDamage(1);
    trap.takeDamage(5);
    trap.takeDamage(2000);
    trap.takeDamage(4294967295);
    trap.takeDamage(0);
    std::cout << std::endl;
    std::cout << "\e[0;32mTesting beRepaired\e[0m" << std::endl;
    trap.beRepaired(0);
    trap.beRepaired(1);
    trap.beRepaired(5);
    trap.beRepaired(4294967295);
    trap.beRepaired(-2);
    trap.beRepaired(0);
}