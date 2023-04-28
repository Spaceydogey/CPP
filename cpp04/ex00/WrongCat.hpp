/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:02:38 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/28 11:59:40 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat(void);
		WrongCat( WrongCat const & src );
		~WrongCat(void);

		WrongCat &operator=( WrongCat const & rhs );
		void		makeSound(void) const;
		std::string	getType(void) const;
	protected:
		std::string	_type;

};


#endif 