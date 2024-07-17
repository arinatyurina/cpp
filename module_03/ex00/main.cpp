/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/17 18:47:01 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	mia("Mia");
	ClapTrap	leo("Leo");

	mia.setDamage(3);
	mia.attack("Rik");
	mia.takeDamage(5);
	mia.beRepaired(1);
	leo.takeDamage(3);
	leo.beRepaired(1);
	leo.beRepaired(1);
}