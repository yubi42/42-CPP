/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:39:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/29 17:03:22 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.hpp"


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

std::string Animal::getType()
{
    return(type);
}

Dog::Dog() : Animal()
{
    std::cout << "Dog created." << std::endl;
    type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark";
}

Cat::Cat() : Animal()
{
    std::cout << "Cat created." << std::endl;
    type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miao";
}