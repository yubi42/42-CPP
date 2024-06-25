/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:13:34 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:50:28 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog created." << std::endl;
    _type = "Dog";
    myBrain = new Brain(_type);
}

Dog::Dog(const Dog &src) : Animal(src) 
{
    std::cout << "Dog copy created." << std::endl;
    myBrain = new Brain(*src.myBrain);
}

Dog& Dog::operator=(const Dog& src)
{
    if(this != &src)
    {
        _type = src._type;
        if (this->myBrain)
            delete myBrain;
        myBrain = new Brain(src._type);
    }
    
	return (*this);
}

Dog::~Dog()
{
    delete (myBrain);
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark";
}
