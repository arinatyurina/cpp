/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:37:31 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/22 14:35:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\nTest from the subject\n\n";
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "\n\nTest for an array of Animal objects\nHalf Dog, half Cat\n\n";
	Animal	*animals[4];
	animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
	std::cout << "\n\nDelete directly dogs and cats as Animals:\n\n";
	for (int i = 0; i != 4; i++)
	{
		delete	animals[i];
	}

	std::cout << "\n\nTest for deep copy\n\n";
	std::cout << "\nConstructors\n";	
	std::cout << "\n\nDog->>>>>\n\n";
	Dog	basic;
	Dog tmp = basic;

	std::cout << "\n\nCat->>>>>\n\n";
	Cat	og;
	Cat copy = og;
	Cat aa (og);
	Cat bb;
	bb = og;
	std::cout << "\nDestructors\n";	
	return 0;
}

/**
 * the copy a Cat or a Dog should be a deep copy.
Dog basic;
{
Dog tmp = basic;
}
If the copy is shallow, tmp and basic will use the same Brain and
the Brain will get deleted with tmp at the end of the scope.
The copy constructor should do a deep copy too.
That's why a clean implementation in orthodox canonical form will
save you from hours of pain.
*/