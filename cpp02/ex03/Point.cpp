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

Point::Point(Point const &to_cp)
{
    *this = to_cp;
    return ;
}

Point   &Point::operator=(Point const &rhs)
{
    this->_x = rhs.x;
    this->_y = rhs.y;
    return (*this);
}