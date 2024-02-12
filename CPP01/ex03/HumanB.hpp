/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:31:18 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 16:12:48 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string humanName);
    void setWeapon(Weapon& humanWeapon);
    void attack(void);
};

#endif