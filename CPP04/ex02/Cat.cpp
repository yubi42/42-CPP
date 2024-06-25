/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:14:07 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:49:32 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat created." << std::endl;
    _type = "Cat";
    myBrain = new Brain(_type);
}

Cat::Cat(const Cat &src) : Animal(src) 
{
    std::cout << "Cat copy created." << std::endl;
    myBrain = new Brain(*src.myBrain);
}

Cat& Cat::operator=(const Cat& src)
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

Cat::~Cat()
{
    delete myBrain;
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "miao";
}
