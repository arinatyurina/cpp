/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:55:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 17:49:21 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap] default constructor has been called" << std::endl;
	name = "unknown";
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), diamondName(name)
{
	std::cout << "[DiamondTrap] constructor with name " << name << " has been called" << std::endl;
	ClapTrap::name = name + "_clap_name";
	health = FragTrap::health;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor has been called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "[DiamondTrap] copy constructor has been called" << std::endl;
	*this = other;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My [DiamondTrap] name is " << diamondName << std::endl;
	std::cout << "My [ClapTrap] name is " << ClapTrap::name << std::endl;
}