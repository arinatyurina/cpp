/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:26:06 by atyurina          #+#    #+#             */
/*   Updated: 2024/08/14 17:17:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "[MateriaSource] Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		materials[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete materials[i];
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.materials[i])
			materials[i] = other.materials[i]->clone();
		else
			materials[i] = NULL;
	}
	std::cout << "[MateriaSource] Copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materials[i])
				delete materials[i];
			if (other.materials[i])
				materials[i] = other.materials[i]->clone();
			else
				materials[i] = NULL;
		}
	}
	std::cout << "[MateriaSource] Copy assignment operator called" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (materials[i] != NULL && i < 4)
		i++;
	if (i > 3)
		std::cout << "MateriaSource can know at most 4 Materias! Can not learn any more" << std::endl;
	else
		materials[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materials[i] && materials[i]->getType() == type) {
			return materials[i]->clone();
		}
	}
	return NULL;
}