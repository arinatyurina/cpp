/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:40:41 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/28 14:36:30 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
}