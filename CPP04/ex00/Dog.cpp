/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:13:34 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:24:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog created." << std::endl;
    _type = "Dog";
}

Dog::Dog( const Dog& other)
{
    _type = other._type;
	std::cout << "Dog copy constructed" << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	_type = other._type;
	std::cout << "Dog copy assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark";
}
