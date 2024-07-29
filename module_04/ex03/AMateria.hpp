/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:44:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 18:10:21 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
protected:
// some data
	std::string	type;
public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	
	AMateria(std::string const & type);

	// some data
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif

/**
 * A concrete class is an ordinary class 
 * which has no purely virtual functions 
 * and hence can be instantiated.
*/