/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:54:49 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/11 13:30:05 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed &src)
{
    this->copy(src);
}

Fixed::Fixed(const int &num) : value(num << fract_bits)
{
}

Fixed::Fixed(const float &num) : value(roundf(num * (1 << fract_bits)))
{
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

//----------- ex 02 -----------

    Fixed Fixed::operator+(const Fixed& src) const
    {
        Fixed tmp;
        tmp.value = value + src.value;
        return (tmp);
    }

    Fixed Fixed::operator-(const Fixed& src) const
    {
        Fixed tmp;
        tmp.value = value - src.value;
        return (tmp);
    }

    Fixed Fixed::operator*(const Fixed& src) const
    {
        Fixed tmp;
        tmp.value = (value * src.value) / (1 << fract_bits);
        return (tmp);
    }

    Fixed Fixed::operator/(const Fixed& src) const
    {
        Fixed tmp;
        tmp.value = (value * (1 << fract_bits)) / src.value;
        return (tmp);
    }

    bool Fixed::operator>(const Fixed& src) const
    {
        return (value > src.value);
    }

    bool Fixed::operator<(const Fixed& src) const
    {
        return (value < src.value);
    }

    bool Fixed::operator>=(const Fixed& src) const
    {
        return (value >= src.value);
    }

    bool Fixed::operator<=(const Fixed& src) const
    {
        return (value <= src.value);
    }

    bool Fixed::operator==(const Fixed& src) const
    {
        return (value == src.value);
    }

    bool Fixed::operator!=(const Fixed& src) const
    {
        return (value != src.value);
    }

    Fixed& Fixed::operator++(void)
    {
        ++value;
        return (*this);
    }

    Fixed Fixed::operator++(int)
    {
        Fixed old (*this);
        ++(*this);
        return (old);
    }

    Fixed& Fixed::operator--(void)
    {
        --value;
        return (*this);
    }

    Fixed Fixed::operator--(int)
    {
        Fixed old (*this);
        --(*this);
        return (old);
    }

    Fixed& Fixed::max(Fixed& fp1, Fixed& fp2)
    {
        if (fp2 > fp1)
            return (fp2);
        return (fp1);
    }

    Fixed& Fixed::min(Fixed& fp1, Fixed& fp2)
    {
        if (fp2 < fp1)
            return (fp2);
        return (fp1);
    }

    const Fixed& Fixed::max(const Fixed& fp1, const Fixed& fp2)
    {
        if (fp2 > fp1)
            return (fp2);
        return (fp1);
    }

    const Fixed& Fixed::min(const Fixed& fp1, const Fixed& fp2)
    {
        if (fp2 < fp1)
            return (fp2);
        return (fp1);
    }
