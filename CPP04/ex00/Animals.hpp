/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animals.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:33:25 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/29 17:05:22 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALS_HPP
#define ANIMALS_HPP


#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
    
public:
    Animal();
    virtual ~Animal();
    std::string getType();
    virtual void makeSound() const;
};

class Dog : public Animal
{
public:
    Dog();
    ~Dog();
    void makeSound() const;
};

class Cat : public Animal
{
public:
    Cat();
    ~Cat();
    void makeSound() const;
};

#endif
