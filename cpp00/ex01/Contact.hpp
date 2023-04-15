/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:30:29 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 18:58:45 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>


class Contact
{
	private:
		std::string _first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_nbr;
		std::string	_darkest_secret;
		std::string	_display;
		std::string	_listing;
		void		_create_display(void);
		void		_create_listing(void);

	public:
		Contact();
		~Contact(void);
		void		set_contact(std::string first, std::string last, std::string nick,
				 				std::string nbr, std::string secret);
		std::string	get_display(void);
		std::string	get_listing(void);
};

#endif