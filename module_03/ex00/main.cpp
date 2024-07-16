/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 12:08:31 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	mia("Mia");
	ClapTrap	leo("Leo");

	mia.setDamage(3);
	//leo.getStatus();
	//mia.getStatus();
	mia.attack("Rik");
	mia.beRepaired(1);
	leo.takeDamage(3);
	//mia.getStatus();
	//leo.getStatus();
	leo.beRepaired(1);
	leo.beRepaired(1);
	leo.beRepaired(1);
	leo.beRepaired(1);
	leo.beRepaired(0);
	//leo.getStatus();
}