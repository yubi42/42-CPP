/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:54:49 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/11 12:33:50 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& cpy) 
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(cpy.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

Fixed& Fixed::operator=(const Fixed& src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->setRawBits(src.getRawBits());
    return *this;
}