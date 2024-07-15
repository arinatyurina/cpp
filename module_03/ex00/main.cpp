/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:12:04 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/15 18:46:22 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	cat("Tom");
	ClapTrap	mouse("Jerry");

	cat.setDamage(3);
	mouse.getStatus();
	cat.getStatus();
	cat.attack("Jerry");
	mouse.takeDamage(3);
	cat.getStatus();
	mouse.getStatus();
	mouse.beRepaired(2);
	mouse.getStatus();
}