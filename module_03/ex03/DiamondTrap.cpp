/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:55:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 21:00:47 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap] default constructor has been called" << std::endl;
	name = "unknown";
	health = 100; // FragTrap::health;
	energy = 50; //ScavTrap::energy;
	damage = 30; //FragTrap::damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), diamondName(name)
{
	std::cout << "[DiamondTrap] constructor with name " << name << " has been called" << std::endl;
	ClapTrap::name = name + "_clap_name";
	health = 100; // FragTrap::health;
	energy = 50; //ScavTrap::energy;
	damage = 30; //FragTrap::damage;
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