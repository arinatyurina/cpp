/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:38:13 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 18:22:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[FragTrap] default constructor has been called" << std::endl;
	name = "unknown";
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) //to pass name to base class
{
	std::cout << "[FragTrap] constructor with name " << name << " has been called" << std::endl;
	this->name = name;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << name << " destructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "[FragTrap] copy constructor has been called" << std::endl;
	*this = other; //may e=need to delete it
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "[FragTrap] copy assignment operator has been called" << std::endl;
	name = other.name;
	health = other.health;
	energy = other.energy;
	damage = other.damage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (health == 0)
		std::cout << name << " is dead and can not attack anymore [FragTrap]." << std::endl;
	else
	{
		if (energy > 0)
		{
			std::cout << name << " attacks " << target << ", causing " << damage << " points of damage [FragTrap]!" << std::endl;
			energy -= 1;
		}
		else
			std::cout << name << " has no energy to attack [FragTrap]." << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] " << name << " requests: High fives, guys!" << std::endl;
}