/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:41:17 by atyurina          #+#    #+#             */
/*   Updated: 2024/09/27 14:07:55 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "[Animal] Constructor called" << std::endl;
	type = "Not assigned";
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "[Animal] makeSound function called" << std::endl;
}

std::string	const& Animal::getType(void) const
{
	return (type);
}