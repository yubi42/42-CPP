/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:54:06 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/18 20:07:59 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap one("one");
    FragTrap two("two");
    two.attack("one");
    one.takeDamage(30);
    one.attack("two");
    two.takeDamage(20);
    one.guardGate();
    two.highFivesGuys();
}