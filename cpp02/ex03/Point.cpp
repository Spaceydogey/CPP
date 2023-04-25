/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:29:50 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 22:54:44 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
    return ;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
    return ;
}

Point::Point(Point const &to_cp) : _x(to_cp.getX()), _y(to_cp.getY())
{
    return ;
}

Point   &Point::operator=(Point const &rhs)
{
    (void)rhs;
    return (*this);
}

Fixed   Point::getX(void) const
{
    return (this->_x);
}

Fixed   Point::getY(void) const
{
    return (this->_y);
}

Point::~Point(void)
{
    return ;
}
