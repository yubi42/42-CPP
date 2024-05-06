/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 01:02:02 by yubi42            #+#    #+#             */
/*   Updated: 2024/03/11 11:17:30 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* pet[10];
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2)
            pet[i] = new Dog();
        else
            pet[i] = new Cat();
    }

        for (int i = 0; i < 10; ++i)
    {
            delete(pet[i]);
    }

    std::cout << std::endl;
    Cat basic;
    Cat tmp = basic;
}
