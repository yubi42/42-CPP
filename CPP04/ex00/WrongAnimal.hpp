/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:05:54 by yubi42            #+#    #+#             */
/*   Updated: 2024/06/24 18:57:03 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMALS_HPP
#define WRONGANIMALS_HPP


#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
        
    public:
        WrongAnimal();
        ~WrongAnimal();
        
        std::string getType();
        void makeSound() const;
};


class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        void makeSound() const;
};

#endif
