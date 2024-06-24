/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:01:41 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/24 12:09:53 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int i = 5;

	Zombie *horde = zombieHorde(i, "no brain");
	for (int j = 0; j < i; j++)
	{
		horde[j].announce();
	}
	delete [] horde;
	return (0);
}