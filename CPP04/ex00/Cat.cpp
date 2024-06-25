/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:14:07 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:44:59 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat created." << std::endl;
    _type = "Cat";
}

Cat::Cat( const Cat& other)
{
    _type = other._type;
	std::cout << "Cat copy constructed" << std::endl;
}

Cat &Cat::operator=( const Cat& other )
{
	_type = other._type;
	std::cout << "Cat copy assigned" << std::endl;
	return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miao";
}
