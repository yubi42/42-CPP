/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:05:30 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/15 20:53:43 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string clapTrap) : name(clapTrap), hp(10), ep(10), ad(0), dead(false), energy(true)
{
    std::cout << "Creating - ClapTrap: \"" << name << "\", HP: " << hp << ", EP: " << ep << ", AD: " << ad << std::endl;
}

ClapTrap::~ClapTrap()
{
     std::cout << "Destroying - ClapTrap: \"" << name << "\""<< std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hp == 0)
    {
        std::cout << "ClapTrap: \"" << name << "\" is dead and cannot do anything." << std::endl;
        return ;
    }
    if (ep == 0)
    {
        energy = false;
        std::cout << "ClapTrap: \"" << name << "\" has no EP to attack." << std::endl;
        return ;
    }
    --ep;
    std::cout << "ClapTrap: \"" << name << "\" uses 1EP to attack \"" << target << "\" and has now " << ep << "EP. ";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hp == 0)
    {
        std::cout << "There is no use to damage ClapTrap: \"" << name << "\" - it is already dead." << std::endl;
        return ;
    }
    hp -= amount;
    std::cout << "ClapTrap: \"" << name << "\" took " << amount << " dmg ";
    if (hp <= 0)
    {
        hp = 0;
        dead = true;
        std::cout << "and died." << std::endl;
        return;
    }
    std::cout << "and has now " << hp << "HP." << std::endl;
        
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hp == 0)
    {
        std::cout << "ClapTrap: \"" << name << "\" is dead and cannot do anything." << std::endl;
        return ;
    }
    if (ep == 0)
    {
        energy = false ;
        std::cout << "ClapTrap: \"" << name << "\" has no EP to repair." << std::endl;
        return ;
    }
    --ep;
    hp += amount;
    std::cout << "ClapTrap: \"" << name << "\" used 1EP to repair for: " << amount << " and has now " << ep << "EP and " << hp << "HP." << std::endl;
}
