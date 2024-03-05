/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:54:06 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/19 18:20:36 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dia("Diamond");
    dia.attack("BadBoy");
    dia.whoAmI();
    dia.guardGate();
    dia.highFivesGuys();
}