/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:01:30 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/18 20:05:43 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hp = 100;
    ep = 100;
    ad = 30;
    std::cout << "Creating - FragTrap \"" << name << "\": " << hp << "HP, " << ep << "EP, " << ad << "AD." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "Destroying FragTrap - " << name << std::endl;
}

void FragTrap::attack(const std::string& target)
{
if (hp > 0 && ep > 0)
    std::cout << "FragTrap \"" << name << "\" attacks \"" << target << "\" for " << ad << "dmg." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap \"" << name << "\" High-Fives everyone!" << std::endl;
}