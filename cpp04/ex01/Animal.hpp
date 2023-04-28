/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 16:47:52 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{

	public:

		Animal(void);
		Animal( Animal const & src );
		virtual ~Animal(void);

		Animal &		operator=( Animal const & rhs );
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		virtual Brain	*getBrain(void) const;
	protected:
		std::string	_type;

};


#endif 