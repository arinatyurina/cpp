/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:13:49 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/11 17:40:53 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data*> (raw));
}
