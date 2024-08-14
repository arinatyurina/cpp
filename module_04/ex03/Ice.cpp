/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:08:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/14 15:01:13 by atyurina         ###   ########.fr       */
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
	std::cout<< "* shoots an ice bolt at " << target.getName() << " *\n";
}


/**
 * It creates a new instance of Ice and returns a pointer to it. 
 * This ensures that when you call clone() on an Ice object,
 * you get a new Ice object. 
*/
Ice* Ice::clone(void) const
{
	Ice *clone = new Ice;
	return (clone);
}