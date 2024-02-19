/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:54:06 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/13 17:40:10 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>

void action(ClapTrap &one, ClapTrap &two)
{
    if (std::rand() % 2)
    {
        one.attack("enemy");
        if (one.energy && !one.dead)
            two.takeDamage((std::rand() % 3) + 1);
    }
    else
        one.beRepaired((std::rand() % 3));
}

int main()
{
    ClapTrap one("one");
    ClapTrap two("two");
    std::srand(std::time(NULL));

    while ((!one.dead && !two.dead))
    {
        if (std::rand() % 2)
        {
            action(one, two);  
            if (!one.dead || !two.dead) 
                action(two, one);         
        }
        else
        {
            action(two, one);
            if (!one.dead || !two.dead) 
                action(one, two);
        }
        if (!one.energy && !two.energy)
        {
            std::cout << "Both are out of energy. Noone wins." << std::endl;
            break ;
        }
        if (one.dead)
            std::cout << "one died. the winner is two!" << std::endl;
        if (two.dead)
            std::cout << "two died. the winner is one!" << std::endl;
    }
}