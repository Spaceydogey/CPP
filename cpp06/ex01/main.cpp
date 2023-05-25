/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:55:57 by hdelmas           #+#    #+#             */
/*   Updated: 2023/05/25 16:29:27 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data 		data;
	Data 		*res;
	uintptr_t	raw;

	data.value = 157;
	data.value2 = 90.12f;

	std::cout << "value: " << data.value << std::endl;
	std::cout << "value2: " << data.value2 << std::endl;
	std::cout << "adress: " << &data << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << raw << std::endl;
	res = Serializer::deserialize(raw);
	std::cout << "value: " << res->value << std::endl;
	std::cout << "value2: " << res->value2 << std::endl;
	std::cout << "adress: " << &res << std::endl;
}