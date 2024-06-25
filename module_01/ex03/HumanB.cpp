/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:05 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/25 12:55:44 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

/* When the setWeapon method accepts a Weapon object by reference instead of by value, it allows the method 
to store a pointer to an existing Weapon object that exists outside the scope of the method. 
This means that the Weapon object is not destroyed when the method finishes executing, 
because the method does not create a temporary copy of the object. 
it keeps a reference (through a pointer) to the original Weapon object, 
which continues to exist as long as it is needed.*/
void	HumanB::setWeapon(Weapon &type)
{
	this->weapon = &type;
}

void	HumanB::attack(void) const
{
	if (weapon != NULL)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " doesn't have a weapon to attack" << std::endl;
}
