/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:42:20 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/14 23:12:56 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string first, std::string last, std::string nick,
			std::string nbr, std::string secret) : 
			first_name(first), last_name(last), nickname(nick), 
			phone_nbr(nbr), darkest_secret(secret)
{
	std::cout << this->last_name + " " + this->first_name
					+ "added to the contact list" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << this->last_name + " " + this->first_name
					+ "deleted from the contact list" << std::endl;
}