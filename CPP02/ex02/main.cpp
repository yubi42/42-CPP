/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:50:32 by yubi42            #+#    #+#             */
/*   Updated: 2024/04/29 14:31:32 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
Fixed a(1);
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed c(1);
Fixed const d( Fixed( 10.1016f ) / Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << d << std::endl;
std::cout << c << std::endl << std::endl;

std::cout << c++ << std::endl;
std::cout << c << std::endl;
std::cout << --c << std::endl << std::endl;

std::cout << (a > c) << std::endl;
std::cout << (a < c) << std::endl;
std::cout << (a >= c) << std::endl;
std::cout << (a <= c) << std::endl << std::endl;

std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
return 0;
}
