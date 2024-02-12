/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:02:31 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/31 20:46:53 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() : complaint("There is nothing to complain :)")
{
    msg[0].first = "DEBUG";
    msg[0].second = &Harl::debug;
    msg[1].first = "INFO";
    msg[1].second = &Harl::info;
    msg[2].first = "WARNING";
    msg[2].second = &Harl::warning;
    msg[3].first = "ERROR";
    msg[3].second = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "i want to get debuged!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "i need some info!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "warning, warning, warning..." << std::endl;
}

void Harl::error(void)
{
    std::cout << "beep bop beeewww.... ERROR peeeeeep --------------------" << std::endl;
}

void Harl::harlFilter(int i)
{    
    switch (i)
    {
    case 0:
        (this->*(msg[3].second))();
        (this->*(msg[2].second))();
        (this->*(msg[1].second))();
        (this->*(msg[0].second))();
        break;
    case 1:
        (this->*(msg[2].second))();
        (this->*(msg[1].second))();
        (this->*(msg[0].second))();
        break;
    case 2:
        (this->*(msg[1].second))();
        (this->*(msg[0].second))();
        break;
    case 3:
        (this->*(msg[0].second))();
        break;
    default:
        break;
    }}

void Harl::complain(std::string level)
{
   for (int i = 0; i < 4; i++)
    {
        if (level == msg[i].first)
            harlFilter(i);
    }
}
