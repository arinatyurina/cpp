/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 18:35:06 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	frank("Frank");
	FragTrap	froggie("Froggie");

	frank.attack("Billie");
	frank.takeDamage(1);
	frank.beRepaired(1);
	frank.guardGate();
	froggie.attack("Billie");
	froggie.takeDamage(1);
	froggie.beRepaired(1);
	froggie.highFivesGuys();
}