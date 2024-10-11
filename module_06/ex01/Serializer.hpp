/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:13:42 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/11 17:23:25 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <string>
#include <iostream>

struct Data
{
	int num;
	std::string	str;
};

class Serializer
{
private:
	Serializer(){};
	~Serializer(){};
	Serializer(const Serializer& other);
	virtual Serializer& operator=(const Serializer& other) = 0;

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif