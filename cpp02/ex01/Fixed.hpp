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
# include <iostream>

class Fixed
{
	private:
		int					_value;
		static int const	_binPointPos;
;

	public:
		Fixed(void);
		Fixed(Fixed const &to_cp);
		Fixed(int	integer);
		Fixed(float	floating);
		~Fixed();
		Fixed 			& operator=(Fixed const &rhs);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static int		getbinPointPos(void);
};


std::ostream	& operator<<(std::ostream &o, Fixed const &rhs);
#endif 
	// after_point = (this->_value << (32 - Fixed::_binPointPos)
	// 				>> (32 - Fixed::_binPointPos));
	// res = 0;
	// for (int i = 1; i <= Fixed::_binPointPos; i++)
	// 	res += (float)(after_point << i - 1 >> (Fixed::_binPointPos - i))
	// 			/ (1 << i);