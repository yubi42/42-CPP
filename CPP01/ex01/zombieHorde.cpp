/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:40 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/27 22:04:18 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
    Zombie* zombieHorde = new Zombie[N]; 

    for (int i = 0; i < N; i++) 
    {
        zombieHorde[i].setName(name);
        zombieHorde[i].announce();
    }

    return zombieHorde; 
}