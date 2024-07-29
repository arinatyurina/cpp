/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:08:30 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/29 18:40:42 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
	/* data */
public:
	Ice();
	virtual ~Ice();
	Ice(const Ice& other);
	Ice& operator=(const Ice& other);

	void use(ICharacter& target);

	Ice* clone() const;
};

#endif