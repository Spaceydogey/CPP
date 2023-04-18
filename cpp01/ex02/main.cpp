/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:12 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/18 16:30:43 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	//main exercice
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;
		 
	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;

	//added tests
	std::string beep = "boop";
	
	std::cout << "Making changes.." << std::endl;
	stringPTR = &beep; 
	
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;

	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;

	 
	std::cout << "Reverting changes.." << std::endl;
	stringPTR = &string;
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;

	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;
	
	std::cout << "Making changes.." << std::endl;
	stringREF = beep;
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;

	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;

	std::cout << "Reverting changes.." << std::endl;
	stringREF = string;
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;

	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;

	std::cout << "Making changes.." << std::endl;
	string = "beep";
	std::cout << "Printing address.." << std::endl;
	std::cout << &string << std::endl; 
	std::cout << &stringREF << std::endl; 
	std::cout << stringPTR << std::endl;

	std::cout << "Printing values.." << std::endl;
	std::cout << string << std::endl; 
	std::cout << stringREF << std::endl; 
	std::cout << *stringPTR << std::endl;
}