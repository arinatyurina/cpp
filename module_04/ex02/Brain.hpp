/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:14:28 by atyurina          #+#    #+#             */
/*   Updated: 2024/07/23 17:14:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>

class Brain
{
protected:
	std::string	ideas[100];
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
};

#endif