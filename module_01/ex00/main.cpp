/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:01:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/21 17:16:05 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*z1;
	z1 = newZombie("first");
	delete z1;
	Zombie	*z2;
	z2 = newZombie("second");
	delete z2;
	randomChump("third");
	randomChump("fourth");
	return (0);
}