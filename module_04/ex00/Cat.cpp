/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:05:12 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/29 13:52:41 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "[Cat] Constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "[Cat] Meow!" << std::endl;
}