/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 18:16:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diana("Diana");

	diana.whoAmI();
	//diana.getStatus();
	diana.attack("Mob");
	diana.takeDamage(20);
	//diana.getStatus();
	diana.beRepaired(10);
	//diana.getStatus();
	diana.highFivesGuys();
	diana.guardGate();
}