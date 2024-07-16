/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:14:20 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 15:25:53 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("unknown")
{
	std::cout << "ClapTrap default constructor has been called" << std::endl;
	health = 10;
	energy = 10;
	damage = 0;
}

ClapTrap::ClapTrap(std::string name): name(name)
{
	std::cout << "ClapTrap constructor with name " << name << " has been called" << std::endl;
	health = 10;
	energy = 10;
	damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator has been called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		health = other.health;
		energy = other.energy;
		damage = other.damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (health == 0)
		std::cout << name << " is dead and can not attack anymore (ClapTrap)." << std::endl;
	else
	{
		if (energy > 0)
		{
			std::cout << name << " attacks " << target << ", causing " << damage << " points of damage (ClapTrap)!" << std::endl;
			energy -= 1;
		}
		else
			std::cout << name << " has no energy to attack (ClapTrap)." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ( health == 0)
		std::cout << name << " is already dead hence can not take any more damage." << std::endl;
	else if (amount == 0)
		std::cout << "Okay. ClapTrap " << name << " got no damage. Maybe try again?" << std::endl;
	else
	{
		if (amount >= health)
		{
			health = 0;
			std::cout << name << " was damaged and died." << std::endl;
		}
		else
		{
			health -= amount;
			std::cout << name << " was damaged and lost " << amount << " hit points." << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (health == 0)
		std::cout << name << " is dead hence can not repair itself." << std::endl;
	else if (amount == 0)
		std::cout << "Okay. ClapTrap " << name << " got 0 for repairing. Maybe try again?" << std::endl;
	else
	{
		if (amount + health > 10)
			std::cout << "ClapTrap can have up to 10 hit points in total. Maybe try again?" << std::endl;
		else
		{
			if (energy > 0)
			{
				std::cout << name << " repairs itself with " << amount << " points." << std::endl;
				health += amount;
				energy -= 1;
			}
			else
				std::cout << name << " has no energy to be repaired." << std::endl;
		}
	}
}

void ClapTrap::getStatus() const
{
	std::cout << "Status of " << name << std::endl;
	std::cout << "Hit points: " << health << std::endl;
	std::cout << "Energy points: " << energy << std::endl;
	std::cout << "Attack damage: " << damage << std::endl;
	if (health == 0 )
		std::cout << "Status: dead" << std::endl;
	else
		std::cout << "Status: alive" << std::endl;
}

void ClapTrap::setDamage(int amount)
{
	std::cout << name << " got attack damage set to " << amount << "." << std::endl;
	damage = amount;
}