/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:41:21 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 17:18:13 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	virtual void	makeSound(void) const;
	std::string	const&getType(void) const;
};

#endif

/**
 * 
 * A virtual function (also known as virtual methods) 
 * is a member function that is declared within a base class and 
 * is re-defined (overridden) by a derived class. When you refer 
 * to a derived class object using a pointer or a reference to the base class, 
 * you can call a virtual function for that object and execute the derived class’s version of the method.
 * 
 * Making base class destructor virtual guarantees 
 * that the object of derived class is destructed properly,
 * i.e., both base class and derived class destructors are called. 
*/