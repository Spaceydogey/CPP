/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:42:20 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 19:12:33 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

static std::string	formating(std::string str)
{
	int	i;
	std::string	res;
	
	i = -1;
	if (str.length() <= 10)
	{
		while (++i < 10 - str.length())
			res += " ";
		res += str;
	}
	else 
	{

		while (++i < 9)
			res += str[i];
		res += ".";
	}
	return (res);
}

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""),
					_phone_nbr(""), _darkest_secret("")
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_contact(std::string first, std::string last, std::string nick,
				 std::string nbr, std::string secret)
{
	this->_first_name = first;
	this->_last_name = last;
	this->_nickname = nick;
	this->_phone_nbr = nbr;
	this->_darkest_secret = secret;
	this->_create_display();
	this->_create_listing();
	std::cout << this->_last_name + " " + this->_first_name
					+ " created" << std::endl;
	return ;
}

void	Contact::_create_listing(void)
{
	this->_listing = "|";
	this->_listing += formating(this->_first_name);
	this->_listing += "|";
	this->_listing += formating(this->_last_name);
	this->_listing += "|";
	this->_listing += formating(this->_nickname);
	this->_listing += "|";
}

std::string	Contact::get_listing(void)
{
	return (this->_listing);
}


void	Contact::_create_display(void)
{
	this->_display = "First name : " +  this->_first_name + "\n";
	this->_display += "Last name : " + this->_last_name + "\n";
	this->_display += "Nickname : " + this->_nickname + "\n";
	this->_display += "Phone number : " + this->_phone_nbr + "\n";
	this->_display += "Darkest secret : " + this->_darkest_secret + "\n";
}

std::string	Contact::get_display(void)
{
	return (this->_display);
}
