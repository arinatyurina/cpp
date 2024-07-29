/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:37:31 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 17:37:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal a; // This will cause a compilation error because Animal is abstract
	// a.getType();
	// a.makeSound();
	Dog dog;
	dog.makeSound(); // Outputs: [Dog] Bark!

	Animal* animalPtr = new Dog(); // Valid polymorphic behavior
	animalPtr->makeSound(); // Outputs: [Dog] Bark!
	delete animalPtr;

	return 0;
}

/**
 * Polymorphism means "many forms", and it occurs
 * when we have many classes that are related 
 * to each other by inheritance.
*/