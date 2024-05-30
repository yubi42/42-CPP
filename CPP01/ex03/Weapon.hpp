/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:32:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/08 13:41:39 by jborner          ###   ########.fr       */
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
        Weapon(const std::string weaponType);
        void setType(const std::string weaponType);
        const std::string getType() const;
};

#endif