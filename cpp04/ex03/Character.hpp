/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:43:17 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/01 14:54:09 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include   <iostream>
# include   <string>
# include	"AMateria.hpp"

# define     INV_SIZE 4

class Character : public ICharacter
{
	public:
		// Constructors
		Character();
		Character(std::string name);
		Character(const Character &to_cp);
		
		// Destructor
		virtual ~Character();
		
		// Operators
		Character 					&operator=(const Character &rhs);
		
		//Member Functions
		virtual std::string const   &getName() const;
		virtual AMateria            *getMateria(int idx) const;
		virtual void                equip(AMateria* m);
		virtual void                unequip(int idx);
		virtual void                use(int idx, ICharacter& target);
		
	private:
		AMateria            		*_inventory[INV_SIZE];
		std::string const   		_name;
		
		
};

#endif