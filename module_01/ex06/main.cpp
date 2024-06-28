/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:51:29 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/28 14:00:12 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
The program harlFilter takes as argument any of the log levels ("DEBUG",
"INFO", "WARNING" or "ERROR"). It should then display just the messages
that are at the same level or above (DEBUG < INFO < WARNING < ERROR). This
must be implemented using a switch statement with a default case.
Once again, no if/elseif/else anymore please.*/

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "You can pass only one parameter" << std::endl;
		return (1);
	}
	Harl	h;
	h.complain(argv[1]);
}

