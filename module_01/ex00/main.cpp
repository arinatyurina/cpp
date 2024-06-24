/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:01:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/24 11:26:01 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z1;
	z1 = newZombie("first");
	z1->announce();
	delete z1;
	Zombie	*z2;
	z2 = newZombie("second");
	z2->announce();
	delete z2;
	randomChump("third");
	randomChump("fourth");
	return (0);
}