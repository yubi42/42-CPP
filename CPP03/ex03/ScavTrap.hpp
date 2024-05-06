/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:28:22 by yubi42            #+#    #+#             */
/*   Updated: 2024/05/04 14:38:48 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
protected:
    int hp;
    int ad;
    int ep;
    
public:
    ScavTrap(std::string name);
    ~ScavTrap();
    virtual void attack(const std::string& target);
    void guardGate(void);
};

#endif