/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:49:05 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/19 18:33:49 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
    std::cout << "Creating - DiamondTrap \"" << name << "\": " << hp << "HP, " << ep << "EP, " << ad << "AD." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destroying DiamondTrap - " << name << std::endl;
}

// void DiamondTrap::attack(const std::string& target)
// {
//     ScavTrap::attack(target);
// }

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap says I am: \"" << name << "\" ClapTrap says I am: \"" << ClapTrap::name << "\"" << std::endl;
}
