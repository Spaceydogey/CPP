/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:06:28 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 13:29:49 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class ICharacter
{
	public:
		// Constructors
		ICharacter(void) {};
		ICharacter(const ICharacter &to_cp) {(void) to_cp};
		
		// Destructor
		virtual ~ICharacter() {};
		// Operators
		ICharacter & operator=(const ICharacter &rhs) {(void)rhs;return (*this);};
		
        //Member Functions
		virtual std::string const   &getName() const = 0;
		virtual AMateria            &getMateria(int idx) const = 0;
        virtual void                equip(AMateria* m) = 0;
        virtual void                unequip(int idx) = 0;
        virtual void                use(int idx, ICharacter& target) = 0;
};

#endif