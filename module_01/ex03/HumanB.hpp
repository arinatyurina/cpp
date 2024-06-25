/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:28:09 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/25 12:53:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;
public:
	HumanB(std::string name);
	void	setWeapon(Weapon& type);
	void	attack() const;
};

#endif