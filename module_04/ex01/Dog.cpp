/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/22 14:40:19 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "[Dog] Constructor called" << std::endl;
	type = "Dog";
	brainDog = new Brain();
}

Dog::~Dog()
{
	delete brainDog;
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	type = other.type;
	brainDog = new Brain(*other.brainDog);
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		delete brainDog;
		brainDog = new Brain(*other.brainDog);
		std::cout << brainDog << " vs " << other.brainDog << "\n"; //prove that Dogs have different Brain addresses
	}
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] Bark!" << std::endl;
}