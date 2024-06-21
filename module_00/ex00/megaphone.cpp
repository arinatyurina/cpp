/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:41:33 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/05 15:41:37 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cout represents the standard output stream
insert a sequence of characters into the standard output
stream (which usually is the screen)

cout is declared in the iostream standard file
within the std
*/

#include <iostream>
#include <cctype>

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
				argv[i][j] = (char)toupper(argv[i][j]);
			std::cout << argv[i];
		}
	}
	std::cout << std::endl;
	return 0;
}
