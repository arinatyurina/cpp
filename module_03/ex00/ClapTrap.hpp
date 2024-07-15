/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:14:23 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/15 18:43:20 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * Orthodox Canonical Form:
 *  Default constructor
 *  Copy constructor
 *  Copy assignment operator
 *  Destructor
*/

class ClapTrap
{
private:
	std::string		name;
	unsigned int	health;
	unsigned int	energy;
	unsigned int	damage;
public:

	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);

	ClapTrap(std::string name);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void getStatus() const;
	void setDamage(int amount);
};