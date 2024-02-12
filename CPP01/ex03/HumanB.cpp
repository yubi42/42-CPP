/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:21:45 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 16:15:43 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& humanWeapon)
{
    this->weapon = &humanWeapon;
}

void HumanB::attack(void)
{
    if (this->weapon)
        std::cout << this->name << ": attacks with: " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " is unarmed and cannot attack." << std::endl;
}