/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:39:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/11 11:10:28 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal copy created." << std::endl;
	type = src.type;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "no sound";
}

std::string Animal::getType() const
{
    return(type);
}