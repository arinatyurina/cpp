/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:11:22 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 15:36:35 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor has been called" << std::endl;
	name = "unknown";
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) //to pass name to base class
{
	std::cout << "ScavTrap constructor with name " << name << " has been called" << std::endl;
	this->name = name;
	health = 100;
	energy = 50;
	damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor has been called" << std::endl;
	*this = other;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (health == 0)
		std::cout << name << " is dead and can not attack anymore (ScavTrap)." << std::endl;
	else
	{
		if (energy > 0)
		{
			std::cout << name << " attacks " << target << ", causing " << damage << " points of damage (ScavTrap)!" << std::endl;
			energy -= 1;
		}
		else
			std::cout << name << " has no energy to attack (ScavTrap)." << std::endl;
	}
}