/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <atyurina@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:51:32 by atyurina          #+#    #+#             */
/*   Updated: 2024/06/27 21:23:44 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
private:
    /* data */
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
public:
    Harl(/* args */);
    ~Harl();
    void    complain(std::string level);
};

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}


#endif