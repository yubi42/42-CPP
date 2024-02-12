/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:32:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/28 15:35:13 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon();
        Weapon(std::string weaponType);
        void setType(std::string weaponType);
        const std::string getType() const;
};

#endif