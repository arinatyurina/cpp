/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:53:55 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/25 12:27:21 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const&  Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std:: string type)
{
	this->type = type;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

