/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 15:36:15 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
//	ClapTrap	mil("Mil");
	ScavTrap	frank("Frank");
//	ScavTrap	clone_frank(frank);

	frank.attack("Billie");
	frank.takeDamage(1);
	frank.beRepaired(1);
	frank.guardGate();
//	mil.attack("Target");
//	mil.beRepaired(1);
}