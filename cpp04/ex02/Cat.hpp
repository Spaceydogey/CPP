/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 17:07:49 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

	public:

		Cat(void);
		Cat( Cat const & src );
		virtual ~Cat(void);

		Cat &			operator=( Cat const & rhs );
		virtual void	makeSound(void) const;
		Brain			*getBrain(void) const;
		std::string		getType(void) const;	
	private:

		Brain	*_brain;

};


#endif 