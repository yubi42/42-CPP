/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:33:25 by yubi42            #+#    #+#             */
/*   Updated: 2024/05/26 18:26:15 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
    Animal();
    
    
public:
    Animal(const Animal &src);
    Animal& operator=(const Animal& src);
    virtual ~Animal();
    
    std::string getType() const;
    virtual void makeSound() const;
};

#endif
