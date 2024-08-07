/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:37:31 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/23 16:43:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\nAnimal, Dog & Cat:\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog(); // This is OK because Dog is an Animal
	const Animal* i = new Cat(); // This is OK because Cat is an Animal
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete	i;
	delete	j;
	delete	meta;

	std::cout << "\n\nWrongCat from WrongAnimal:\n";
	const WrongAnimal* b = new WrongCat();
	std::cout << b->getType() << " " << std::endl;
	b->makeSound();
	delete	b;

	std::cout << "\n\nJust WrongCat:\n";
	const WrongCat	a;
	std::cout << a.getType() << " " << std::endl;
	a.makeSound();
	return 0;
}