/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:07:46 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 13:46:19 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria,hpp"

class Cure : public AMateria
{
	public:
		// Constructors
		Cure(void);
		Cure(const Cure &copy);
		
		// Destructor
		~Cure(void);
		
		// Operators
		Cure & operator=(const Ice &assign);
        
        //Methodes
        virtual AMateria *	clone () const ;
		virtual	void		use(ICharacter& target);
		
	private:
		
};

#endif