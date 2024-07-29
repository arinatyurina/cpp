/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:12 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 16:54:33 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	std::cout << "[Cat] Constructor called" << std::endl;
	type = "Cat";
	brainCat = new	Brain();
}

Cat::~Cat()
{
	delete brainCat;
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		brainCat = new Brain(*other.brainCat);
	}
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[Car] Meow!" << std::endl;
}