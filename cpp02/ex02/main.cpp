/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:03:48 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/24 11:55:57 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int main( void ) {
    Fixed a;
    Fixed j(1);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a + j - j << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;

    // Fixed c(1);
    // Fixed d(1);
    // Fixed e(2);

    // std::cout << (c == d) << std::endl; // 1
    // std::cout <<  (c != d) << std::endl; // 0
    // std::cout <<  (e != d) << std::endl; // 1
    // std::cout <<  (e < d )<< std::endl; // 0
    // std::cout <<  (c <= d) << std::endl; // 1
    // std::cout <<  (c >= d) << std::endl; // 1
    // std::cout <<  (c > e )<< std::endl; // 0

    return 0;
}