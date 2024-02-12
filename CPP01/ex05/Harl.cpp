/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:02:31 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/31 19:23:18 by yubi42           ###   ########.fr       */
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
    this->complaint = "i want to get debuged!";
}

void Harl::info(void)
{
    this->complaint = "i need some info!";
}

void Harl::warning(void)
{
    this->complaint = "warning, warning, warning...";
}

void Harl::error(void)
{
    this->complaint = "beep bop beeewww.... ERROR peeeeeep --------------------";
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == msg[i].first)
            (this->*(msg[i].second))();
    }
}

void Harl::print(void)
{
    std::cout << this->complaint << std::endl;
    this->complaint = "There is nothing to complain :)";
}