/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:09:06 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/24 14:16:27 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	~Zombie();

	void	announce(void);
	void	setName(std::string str);
};

Zombie* zombieHorde( int N, std::string name );

#endif