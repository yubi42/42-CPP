/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:05 by yubi42            #+#    #+#             */
/*   Updated: 2024/05/04 14:38:14 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
protected:
    int hp;
    int ep;
    int ad;

public:
    FragTrap(std::string name);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif