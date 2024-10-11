/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:14:01 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/11 17:47:03 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
In C++, serialization is the process of converting an object into a sequence
of bytes so that it can be stored in memory or transmitted
across a network and deserialization is the reverse process,
where the byte stream is used to reconstruct the original object. 
*/

void	printData(Data *data)
{
	std::cout << "<--- Data --->" << std::endl;
	std::cout << "int value: " << data->num << std::endl;
	std::cout << "string value: " << data->str << std::endl;
}

int	main()
{
	Data	*data = new Data;

	data->num = 2;
	data->str = "Love";

	printData(data);
	uintptr_t raw =  Serializer::serialize(data);
	std::cout << "<--- Raw --->" << std::endl;
	std::cout << raw << std::endl;
	data = Serializer::deserialize(raw);
	printData(data);

	delete data;
}

/*
The reinterpret_cast operator is used to convert the pointer to any other type of pointer.
It does not perform any check whether the pointer converted is of the same type or not.

uintptr_t
Integer type capable of holding a value converted
from a void pointer and then be converted back to that type
with a value that compares equal to the original pointer.
*/