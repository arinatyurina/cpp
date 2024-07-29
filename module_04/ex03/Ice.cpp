/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:08:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 18:49:50 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "[Ice] Default Constructor called" << std::endl;
	type = "ice";
}

Ice::~Ice()
{
	std::cout << "[Ice] Destructor called" << std::endl;
}

Ice::Ice(const Ice& other)
{
	*this = other;
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout<< "[Ice] * shoots an ice bolt at" << <name> << " *\n";
}


///is it a way to create a clone? double check
Ice* Ice::clone(void) const
{
	Ice *clone = new Ice;

	return (clone);
}