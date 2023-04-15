/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:26:52 by hdelmas           #+#    #+#             */
/*   Updated: 2023/04/15 19:25:38 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# define MAX_SIZE 8

class PhoneBook
{
	private:
		Contact _contacts[MAX_SIZE];

	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(int size);
		void	search(int size);
		Contact	get_contact(int index);
};

#endif