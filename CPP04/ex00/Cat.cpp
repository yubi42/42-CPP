/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:14:07 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/05 20:20:13 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

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
