/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:19:01 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/14 14:55:55 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

/**
 * By using forward declarations, 
 * you inform the compiler that these classes exist, 
 * allowing you to use pointers and references 
 * without needing the full class definitions. 
 * This approach breaks the circular dependency 
 * between AMateria and ICharacter.
*/
class AMateria;

class ICharacter
{
public:
	//ICharacter(std::string name);

	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif

/**
 * Interfaces are implemented using abstract classes
 * A class is made abstract by declaring at least 
 * one of its functions as pure virtual function.
*/