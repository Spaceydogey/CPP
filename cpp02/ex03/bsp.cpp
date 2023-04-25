/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:42:30 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 22:46:39 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

//area triagle from 3 point = abs ( Ax * (By - Cy) + Bx (Cy - Ay) + Cx (Ay - By) ) / 2

static Fixed   f_abs(Fixed value)
{
	if (value < 0)
		return (value * Fixed(-1));
	return (value);
}

static Fixed   area(Point const a, Point const b, Point const c)
{
	return (f_abs((a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY())) / Fixed(2)));
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc(area(a, b, c));
	Fixed abp(area(a, b, point));
	Fixed apc(area(a, point, c));
	Fixed pbc(area(point, b, c));

	if (abp == 0 || apc == 0 ||  pbc == 0)
		return (false);
	return (abc == abp + apc + pbc);

}