/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:30:43 by yubi42            #+#    #+#             */
/*   Updated: 2024/05/04 14:21:49 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hp = 100;
    ep = 50;
    ad = 20;
    std::cout << "Creating - ScavTrap \"" << name  << "\"" << ": " << hp << "HP, " << ep << "EP, " << ad << "AD." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destroying ScavTrap - " << name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
if (hp > 0 && ep > 0)
    std::cout << "ScavTrap \"" << name << "\" attacks \"" << target << "\" for " << ad << "dmg." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap \"" << name << "\" is now in Gate keeper mode." << std::endl;
}