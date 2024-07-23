/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/23 16:04:03 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] Bark!" << std::endl;
}