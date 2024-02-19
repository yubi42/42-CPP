/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:52:26 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/12 21:05:10 by yubi42           ###   ########.fr       */
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
    friend std::ostream& operator<<(std::ostream& os, const Fixed& num);

};

#endif