/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 15:46:04 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
//	ClapTrap	mil("Mil");
	ScavTrap	frank("Frank");
//	ScavTrap	clone_frank(frank);
	FragTrap	froggie("Froggie");

	frank.attack("Billie");
	frank.takeDamage(1);
	frank.beRepaired(1);
	frank.guardGate();
	froggie.highFivesGuys();
//	mil.attack("Target");
//	mil.beRepaired(1);
}