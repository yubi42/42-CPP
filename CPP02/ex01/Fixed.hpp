/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:52:26 by yubi42            #+#    #+#             */
/*   Updated: 2024/04/29 14:04:42 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int	value;
	static const int fract_bits = 8;
    void copy(const Fixed& src);

public:
    Fixed(void);
    Fixed(const Fixed& src);
    Fixed(const int& num);
    Fixed(const float& num);
    ~Fixed();

    void setRawBits( int const raw );
    int getRawBits( void ) const;
    int toInt( void ) const;
    float toFloat( void ) const;
    Fixed& operator=(const Fixed& src);
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif