/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:32 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/27 21:57:41 by yubi42           ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name );

#endif