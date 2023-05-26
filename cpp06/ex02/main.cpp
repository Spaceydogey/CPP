/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:27:18 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/26 11:48:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <stdlib.h>     
# include <time.h>   
# include <exception>   


Base	*generate(void)
{
	
	const int	check = std::rand() % 3;

	if (check == 0)
	{
		std::cout << "Created: 'A'" << std::endl;
		return (static_cast<Base*>(new A()));
	}
	else if (check == 1)
	{
		std::cout << "Created: 'B'" << std::endl;
		return (static_cast<Base*>(new B()));
	}
	else 
	{
		std::cout << "Created: 'C'" << std::endl;
		return (static_cast<Base*>(new C()));
	}
}

void	identify(Base *p)
{
	A	*tryA;
	B	*tryB;
	C	*tryC;

	tryA = dynamic_cast<A*>(p);
	tryB = dynamic_cast<B*>(p);
	tryC = dynamic_cast<C*>(p);
	if (tryA)
		std::cout << "Type: 'A'" << std::endl;
	if (tryB)
		std::cout << "Type: 'B'" << std::endl;
	if (tryC)
		std::cout << "Type: 'C'" << std::endl;
	
}

void	identify(Base &p)
{
	try
	{
		A& tryA = dynamic_cast<A&>(p);
		(void)tryA;
		std::cout << "Type: 'A'" << std::endl;
	}
	catch (std::exception &e){}
	try 
	{
		B& tryB = dynamic_cast<B&>(p);
		(void)tryB;
		std::cout << "Type: 'B'" << std::endl;
	}
	catch (std::exception &e){}

	try 
	{
		C& tryC = dynamic_cast<C&>(p);
		(void)tryC;
		std::cout << "Type: 'C'" << std::endl;
	}
	catch (std::exception &e){}

}

int	main(void)
{
	std::srand(time(0));
	
	Base	*base = generate();
	Base	&rBase = *base;
	std::cout << "POINTER" << std::endl;
	identify(base);
	std::cout << "REFERENCE" << std::endl;
	identify(rBase);
	delete base;
}