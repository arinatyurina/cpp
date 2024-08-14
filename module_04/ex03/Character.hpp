/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:08:40 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/14 16:19:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria*	inventory[4];
public:
	Character();
	~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);

	Character(std::string name);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif

/**
 * AMateria*	inventory[4];
 * Using a pointer to the base class to point to objects of any derived class 
 * This allows you to store and manipulate objects of different types through a common interface.
*/