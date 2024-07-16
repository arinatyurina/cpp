/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:38:13 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 15:44:46 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor has been called" << std::endl;
	name = "unknown";
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) //to pass name to base class
{
	std::cout << "FragTrap constructor with name " << name << " has been called" << std::endl;
	this->name = name;
	health = 100;
	energy = 100;
	damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor has been called" << std::endl;
	*this = other;
}

void	FragTrap::guardGate()
{
	std::cout << "FragTrap " << name << " is now in Gate keeper mode." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests: High fives, guys!" << std::endl;
}