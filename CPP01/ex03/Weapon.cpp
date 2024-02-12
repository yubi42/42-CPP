/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:46:22 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 15:35:15 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string weaponType)
{
    this->setType(weaponType);
}

void Weapon::setType(std::string weaponType)
{
    this->type = weaponType;
}

const std::string Weapon::getType() const
{
    return (this->type);
}
