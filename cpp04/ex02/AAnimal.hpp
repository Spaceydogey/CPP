/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 17:05:27 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class AAnimal
{

	public:

		AAnimal(void);
		AAnimal( AAnimal const & src );
		virtual ~AAnimal(void);

		AAnimal &		operator=( AAnimal const & rhs );
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		virtual Brain	*getBrain(void) const = 0;
	protected:
		std::string	_type;

};


#endif 