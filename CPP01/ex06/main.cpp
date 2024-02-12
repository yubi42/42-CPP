/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:54:54 by yubi42            #+#    #+#             */
/*   Updated: 2024/01/31 20:47:24 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string str = "DEBUG";
    std::cout << "NEW INPUT: " << str << std::endl;
    harl.complain(str);
    str = "INFO";
    std::cout << std::endl;
    std::cout << "NEW INPUT: " << str << std::endl;
    harl.complain(str);
    str = "WARNING";
    std::cout << std::endl;
    std::cout << "NEW INPUT: " << str << std::endl;
    harl.complain(str);
    str = "ERROR";
    std::cout << std::endl;
    std::cout << "NEW INPUT: " << str << std::endl;
    harl.complain(str);
    str = "something";
    std::cout << std::endl;
    std::cout << "NEW INPUT: " << str << std::endl;
    harl.complain(str);


}