/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:40:52 by atyurina          #+#    #+#             */
/*   Updated: 2024/10/14 16:09:38 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand(time(0));
	Base	*baseptr;
	int	i = std::rand() % 3;
	std::cout << "i = " << i << "  i % 3 = " << (i % 3) << std::endl;
	if (i == 0)
	{
		std::cout << "A has been generated" << std::endl;
		baseptr = new A;
	}
	else if (i == 1)
	{
		std::cout << "B has been generated" << std::endl;
		baseptr = new B;
	}
	else
	{
		std::cout << "C has been generated" << std::endl;
		baseptr = new C;
	}
	return (baseptr);
}

void	identify(Base *p)
{
	if (dynamic_cast <A*> (p))
		std::cout << "A has been identified" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "B has been identified" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "C has been identified" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast <A&> (p);
		std::cout << "A has been identified" << std::endl;
		(void)a;
	}
	catch (const std::bad_cast &e){}
	try
	{
 		B &b = (dynamic_cast <B&> (p));
		std::cout << "B has been identified" << std::endl;
		(void)b;
	}
	catch (const std::bad_cast &e){}
	try
	{
		C &c = (dynamic_cast <C&> (p));
		std::cout << "C has been identified" << std::endl;
		(void)c;
	}
	catch (const std::bad_cast &e){}
}