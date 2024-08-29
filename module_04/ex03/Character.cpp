/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:08:37 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/29 15:57:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "[Character] Constructor called" << std::endl;
	name = "unknown";
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "[Character] Constructor with name " << name << " called" << std::endl;
	this->name = name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "[Character] Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

Character::Character(const Character& other) : ICharacter(other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
	std::cout << "[Character] Copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	std::cout << "[Character] Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}
void Character::equip(AMateria* m)
{
	int i = 0;
	while (inventory[i] != NULL && i < 4)
		i++;
	if (i > 3)
		std::cout << "Inventory is full! Can not equip any more" << std::endl;
	else
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx > 3)
		std::cout << "Can not unequip slot " << idx << " There are only slots between 0 and 3" << std::endl;
	else if (inventory[idx] == NULL)
		std::cout << "Slot " << idx << " is empty already" << std::endl;
	else
	{
		inventory[idx] = NULL;
		std::cout << "Slot " << idx << " was successfully unequiped" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		//std::cout << name << " ";
		inventory[idx]->use(target);
	}
}