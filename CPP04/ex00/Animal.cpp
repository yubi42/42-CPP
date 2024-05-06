/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:39:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 20:54:12 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal created." << std::endl;
}

Animal::~Animal()
{
    std::cout << "pew pew" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "no sound";
}

std::string Animal::getType() const
{
    return(type);
}
