/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:39:14 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:19:15 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("")
{
    std::cout << "Animal created." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal " << _type << " copy constructed." << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	_type = other._type;
	std::cout << "Animal " << _type << " copy assigned." << std::endl;
	return *this;
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
    return(_type);
}
