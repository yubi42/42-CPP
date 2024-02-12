/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:30:54 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 16:44:42 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& humanWeapon) : name(humanName), weapon(humanWeapon)
{
}

void HumanA::attack(void)
{
    std::cout << this->name << ": attacks with: " << this->weapon.getType() << std::endl;
}
