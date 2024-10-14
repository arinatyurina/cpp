/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:40:50 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/14 15:57:39 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
public:
	virtual ~Base() {}; //first derived is destructed then base
};

	Base*	generate(void);
	void	identify(Base *p);
	void	identify(Base &p);

#endif