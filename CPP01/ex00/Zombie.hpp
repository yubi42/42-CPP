/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:04:08 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/27 20:12:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;
    void announce(void);

public:
    Zombie( std::string name );
    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif