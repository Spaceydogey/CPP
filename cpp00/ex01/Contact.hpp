/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:30:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/14 18:45:59 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_nbr;
		std::string	darkest_secret;
		
	public:
		Contact(std::string	first,
			std::string	last,
			std::string	nickname,
			std::string	nbr,
			std::string	secret);
		~Contact();

};

#endif