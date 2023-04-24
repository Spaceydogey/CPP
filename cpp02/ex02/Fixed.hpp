/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:16:42 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 14:33:41 by hdelmas          ###   ########.fr       */
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

	public:
		Fixed(void);
		Fixed(Fixed const &to_cp);
		Fixed(int	integer);
		Fixed(float	floating);
		~Fixed();
// Comparison operators
		bool			operator==(Fixed const &rhs);
		bool			operator!=(Fixed const &rhs);
		bool			operator<(Fixed const &rhs);
		bool			operator>(Fixed const &rhs);
		bool			operator<=(Fixed const &rhs);
		bool			operator>=(Fixed const &rhs);
// Arithmetic operators
		Fixed 			& operator=(Fixed const &rhs);
		Fixed 			operator+(Fixed const &rhs);
		Fixed 			operator-(Fixed const &rhs);
		Fixed 			operator/(Fixed const &rhs);
		Fixed 			operator*(Fixed const &rhs);
//Increment operators
		Fixed 			operator++(int);
		Fixed 			operator--(int);
		Fixed 			& operator++(void);
		Fixed 			& operator--(void);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static int		getbinPointPos(void);
};


std::ostream	& operator<<(std::ostream &o, Fixed const &rhs);
#endif