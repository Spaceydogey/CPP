/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 15:38:51 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal(void);
		Animal( Animal const & src );
		~Animal(void);

		Animal &		operator=( Animal const & rhs );
		virtual void	makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string	_type;

};

std::ostream &			operator<<( std::ostream & o, Animal const & i );

#endif 