/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/27 15:38:51 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog(void);
		Dog( Dog const & src );
		virtual ~Dog(void);

		Dog &			operator=( Dog const & rhs );
		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
		std::string		getType(void) const;
	private:

		Brain	*_brain;

};

#endif 