/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:16:42 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/21 16:19:34 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	static int const	_nbrBit;

public:
	Fixed(void);
	Fixed(Fixed const &to_cp);
	~Fixed();
	Fixed 	& operator=(Fixed const &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};


#endif 