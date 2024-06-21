/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:09:06 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/21 15:54:44 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);