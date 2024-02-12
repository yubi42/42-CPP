/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:31:18 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 15:47:38 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(std::string humanName, Weapon& humanWeapon);
    void attack(void);
};


#endif