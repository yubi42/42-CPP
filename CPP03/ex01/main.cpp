/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:54:06 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/15 21:24:12 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap one("one");
    ClapTrap two("two");
    two.attack("one");
    one.takeDamage(0);
    one.attack("two");
    two.takeDamage(20);
    one.guardGate();
}