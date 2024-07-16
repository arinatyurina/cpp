/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonddTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:55:32 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/16 16:02:09 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * when we inherit the common base class key word "virtual" will clear up ambiguity
 * In derived class inherits from borh class1 and class2 the constructor
 * to resolve it we will use parameterised constructor
 * 
 * normally the derived call the baseclass
 * but in our case its gonna call commonbase of base1 and base2
 * 
 * почиатть еще про параметарайсд констрактор. и нужно ли мне это тут использовать
*/

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap(std::string name);
	using ScavTrap::attack;

	void	whoAmI();
};

#endif