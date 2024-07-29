/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:08:23 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 18:37:34 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	/* data */
public:
	Cure();
	virtual ~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	virtual void use(ICharacter& target);

	Cure* clone() const;
};

#endif