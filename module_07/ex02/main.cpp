/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:01:34 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/15 00:33:48 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int>	arr(7);

	for (int i = 0; i < 7; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}
	std::cout << "Size is " << arr.size() << std::endl;
}