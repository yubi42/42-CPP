/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:13:34 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 21:12:17 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog created." << std::endl;
    type = "Dog";
    myBrain = new Brain(type);
}

Dog::~Dog()
{
    delete (myBrain);
    std::cout << "Dog destroyed." << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
    myBrain = new Brain(src.type);
	return (*this);
}

void Dog::makeSound() const
{
    std::cout << "bark";
}
