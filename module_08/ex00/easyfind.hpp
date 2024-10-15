/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:09:11 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/16 00:12:56 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T container, int val)
{
	typename T::iterator	it;
	it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::out_of_range("Container does not contain passed value");
	else
	{
		int index = std::distance(container.begin(), it);
		std::cout << "Value was successfully found at index: " << index << std::endl;
		return (it);
	}
}

#endif