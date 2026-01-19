/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:09:11 by atyurina          #+#    #+#             */
/*   Updated: 2026/01/19 18:45:18 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int val)
{
	typename T::iterator	it; //points to an element inside container and behaves like a pointer
	it = std::find(container.begin(), container.end(), val);
	//returns iterator to the first matching element OR container.end() if not found
	if (it == container.end()) //end points one past the last element
		throw std::out_of_range("Container does not contain passed value");
	else
	{
		int index = std::distance(container.begin(), it);
		//Counts how many steps it takes to go from begin() to it
		std::cout << "Value was successfully found at index: " << index << std::endl;
		return (it);
	}
}

#endif