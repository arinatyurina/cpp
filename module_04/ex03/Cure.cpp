/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:08:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 18:36:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "[Cure] Default Constructor called" << std::endl;
	type = "cure";
}

Cure::~Cure()
{
	std::cout << "[Cure] Destructor called" << std::endl;
}

Cure::Cure(const Cure& other)
{
	*this = other;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}
