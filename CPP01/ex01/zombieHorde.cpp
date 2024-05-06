/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:40 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/08 13:21:43 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) 
{
    Zombie* zombieHorde = new Zombie[n]; 

    for (int i = 0; i < n; i++) 
    {
        zombieHorde[i].setName(name);
        zombieHorde[i].announce();
    }

    return zombieHorde; 
}