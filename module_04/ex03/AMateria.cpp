/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:48:07 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/14 14:48:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "[AMateria] Default Constructor called" << std::endl;
	type = "AMateria";
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
}


AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "[AMateria] Constructor with type called" << std::endl;
	this->type = type;
}

std::string const & AMateria::getType(void) const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] use function called at " << target.getName() << std::endl;
}