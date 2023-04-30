/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:07:46 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/30 19:07:47 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria,hpp"

class Ice : public AMateria
{
	public:
		// Constructors
		Ice(void);
		Ice(const Ice &copy);
		
		// Destructor
		~Ice(void);
		
		// Operators
		Ice & operator=(const Ice &assign);
        
        //Methodes
        virtual AMateria *	clone () const ;
		virtual	void		use(ICharacter& target);
		
	private:
		
};

#endif