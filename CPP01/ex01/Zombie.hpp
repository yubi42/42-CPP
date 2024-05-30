/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:32 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/08 13:21:48 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
private:
    std::string name;
    

public:
    Zombie( std::string name );
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie* zombieHorde( int n, std::string name );

#endif