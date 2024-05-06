/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:46:22 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/08 13:41:55 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string weaponType)
{
    this->setType(weaponType);
}

void Weapon::setType(const std::string weaponType)
{
    this->type = weaponType;
}

const std::string Weapon::getType() const
{
    return (this->type);
}
