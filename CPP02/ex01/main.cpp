/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:50:32 by yubi42            #+#    #+#             */
/*   Updated: 2024/02/10 00:46:55 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

/* int main(void)
{
    Fixed const a(10.0f);
    std::cout << "a is " << a << std::endl;
    std::cout << std::endl;
    Fixed const b(1.0f);
    std::cout << "b is " << b << std::endl;
    std::cout << std::endl;
    Fixed const c(0.01f);
    std::cout << "c is " << c << std::endl;
    std::cout << std::endl;
    Fixed const d(0.00196f);
    std::cout << "d is " << d << std::endl;
    return 0;
} */