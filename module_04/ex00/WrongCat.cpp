/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:30:27 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/29 13:52:53 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "[WrongCat] Constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Meow!" << std::endl;
}