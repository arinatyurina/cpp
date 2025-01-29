/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:13:42 by atyurina          #+#    #+#             */
/*   Updated: 2025/01/29 13:03:14 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>

typedef unsigned long uintptr_t;

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
