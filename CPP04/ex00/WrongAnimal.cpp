/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:08:36 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:56:39 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


#include "Animal.hpp"


WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "Animal created." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "pew pew" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "no sound";
}

std::string WrongAnimal::getType()
{
    return(_type);
}

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat created." << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "miao";
}