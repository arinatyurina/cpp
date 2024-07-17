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
 * normally the derived call the base class
 * but in our case its gonna call commonbase of base1 and base2
*/

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	diamondName;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap(std::string name);
	using ScavTrap::attack; //resolving ambiguity with 'using' (specifies that it should use the attack method from the ScavTrap class)

	void	whoAmI();
};

#endif