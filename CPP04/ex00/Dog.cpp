/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:13:34 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 20:19:48 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

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
