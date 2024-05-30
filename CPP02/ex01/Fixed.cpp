/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:54:49 by yubi42            #+#    #+#             */
/*   Updated: 2024/04/29 14:03:41 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->copy(src);
}

Fixed::Fixed(const int &num) : value(num << fract_bits)
{
    std::cout << "Int constructor called" << std::endl;
}

/* we shift it by one byte. (1 << 8). for int that works: value << 8. for floats we have to use: value * (1 << 8) 
what basically is the same, we just need to use it that way, because of the way memory is stored for floats. if we have 1 
it would be 256. if we have 0.01f it would be 2.56 (rounded to 3) if we have 0.00390625f is around 1. after shifting 
1 byte. about half of it (rounded towards 0) (0.00196f) is still the same - 1. 
if fract_bits would be bigger, it would be more accurate but it would take much more memory. more over it would limit the range by additional 1 byte that would be for 32 bit int 16 less.
it depends on the needs but 1 byte should be enough
 */
/* Fixed::Fixed(const float &num) : value(roundf(num * (1 << fract_bits)))
{
    std::cout << "num: " << num << std::endl;
    std::cout << "(static_cast<int>(num): " << static_cast<int>(num) << std::endl;
    std::cout << "(static_cast<int>(num) << fract_bits: " << (static_cast<int>(num) << fract_bits) << std::endl;
    std::cout << "num * (1 << fract_bits): " << (num * (1 << fract_bits)) << std::endl;
    std::cout << "roundf(num * (1 << fract_bits)): " << roundf(num * (1 << fract_bits)) << std::endl;
    std::cout << "Float constructor called" << std::endl;
} */

Fixed::Fixed(const float &num) : value(roundf(num * (1 << fract_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fract_bits);
}

int Fixed::toInt() const
{
    return (value >> fract_bits);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::copy(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(src.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->copy(src);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &num)
{
    os << num.toFloat();

    return (os);
}