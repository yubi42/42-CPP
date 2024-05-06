/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:49:23 by yubi42            #+#    #+#             */
/*   Updated: 2024/05/04 14:31:38 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
    
public:
    DiamondTrap(std::string name);
    ~DiamondTrap();
    using FragTrap::hp;
    using FragTrap::ad;
    using ScavTrap::ep;
    using ScavTrap::attack;
    void whoAmI(void);
};

#endif